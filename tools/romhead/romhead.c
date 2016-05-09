#include <stdio.h>
#include <string.h>


#define BUFFER 220
#define FIELDS 18


struct
{
	int  size;
	int  hex;
	char data[BUFFER];
}
head [ FIELDS ] =
{
	{ 16, 0, "" }, // Console Name (16)
	{ 16, 0, "" }, // Copyright Information (16)
	{ 48, 0, "" }, // Domestic Name (48)
	{ 48, 0, "" }, // Overseas Name (48)
	{ 14, 0, "" }, // Serial Number (2, 12)
	{  2, 1, "" }, // Checksum (2)
	{ 16, 0, "" }, // I/O Support (16)
	{  4, 1, "" }, // ROM Start Address (4)
	{  4, 1, "" }, // ROM End Address (4)
	{  4, 1, "" }, // Start of Backup RAM (4)
	{  4, 1, "" }, // End of Backup RAM (4)
	{  2, 0, "" }, // "RA" for save ram (2)
	{  2, 1, "" }, // 0xF820 for save ram on odd bytes (2)
	{  4, 1, "" }, // SRAM start address - normally 0x200001 (4)
	{  4, 1, "" }, // SRAM end address - start + 2*sram_size (4)
	{ 12, 0, "" }, // Modem Support (24)
	{ 40, 0, "" }, // Memo (40)
	{ 16, 0, "" }, // Country Support (16)
};



copiar ()
{
	FILE *f1 = fopen ( "rom.0.bin", "rb" );
	FILE *f2 = fopen ( "rom.bin", "wb" );

	fseek ( f1, 0, SEEK_END );
	int pos = ftell ( f1 );
	char str [ 1024 * 1024 ];

	fseek ( f1, 0, SEEK_SET );
	fseek ( f2, 0, SEEK_SET );

	fread  ( str, sizeof(char), pos, f1 );
	fwrite ( str, sizeof(char), pos, f2 );

	fclose ( f1 );
	fclose ( f2 );
}



void fill_head_var ( FILE *f )
{
	int i, j;

	fseek ( f, 0, SEEK_SET );

	for ( i=0; i<FIELDS; i++ )
	{
		fgets ( head[i].data, BUFFER, f );

		char chr  = ' ';
		int  len  = strlen ( head[i].data ) - 1;
		int  size = head[i].size;

		if ( head[i].hex )  // is hexadecimal
		{
			chr  = '0';
			size = size * 2 + 2;
		}

		for ( j=len; j<size; j++ )
		{
			head[i].data[j] = chr;
		}

		head[i].data[size] = '\0';
	}
}



void rewrite_rom ( FILE *f )
{
	int i, j;

	fseek ( f, 256, SEEK_SET );

	for ( i=0; i<FIELDS; i++ )
	{
		if ( head[i].hex )
		{
			for ( j=0; j<head[i].size; j++ )
			{
				char str[3] = { head[i].data[2+j*2+0], head[i].data[2+j*2+1] };
				int val = strtoul ( str, NULL, 16 );

				putc ( val, f );
			}
		}
		else
		{
			fwrite ( head[i].data, sizeof(char),head[i].size, f );
		}
	}
}





void fix_checksum ( FILE *f )
{
	unsigned long val = 0, checksum = 0;

	fseek ( f, 0x0200, SEEK_SET );

	while ( ! feof ( f ) )
	{
		checksum += ( getc ( f ) * 256 );
		checksum += ( getc ( f ) );
	}


	//checksum = checksum << 16;

	//printf( "\%d\n", checksum );
	printf( "\%X", checksum );
}


void fix_rom_size ( FILE *f )
{
	fseek ( f, 0, SEEK_END );
	int i, size = ftell ( f ) - 1 ;

	fseek ( f, 0x1A4, SEEK_SET );

	char hex[255] = {'\0'};
	sprintf ( hex, "%08X", size );

	for ( i=0; i<4; i++ )
	{
		char str[3] = { hex[i*2+0], hex[i*2+1] };
		int val = strtoul ( str, NULL, 16 );

		putc ( val, f );
	}
}



int main ( int argc, char** argv )
{
	//copiar ();

	// TODO - incluir info sobre los parametos
	// TODO - incluir info sobre lo que hace
	// TODO - incluir el fix_checksum a peticion
	// TODO - incluir posibilidad de añadir nº de comilación y fecha
	// TODO - distintos sistemas


	FILE *f1 = fopen ( argv[1], "r+" );
	FILE *f2 = fopen ( argv[2], "r+" );

	fill_head_var ( f1 ) ;
	rewrite_rom   ( f2 ) ;
	//fix_checksum  ( f2 ) ;
	fix_rom_size  ( f2 ) ;

	fclose ( f1 );
	fclose ( f2 );

	return 0;
}



/*


////string padding
//
//#include <stdio.h>
//
//int main ()
//{
//	// sprintf(final, "%.06d", num);        // 'num' is assumed to be of type int
//	// sprintf(final, "%.06d", atoi(num));  // 'num' is assumed to be of type 'char *'
//
//	char *myvar[128];
//
//	sprintf(myvar, "%-6s", "This is a string");
//	myvar[6] = '\0';
//
//	printf ("\n#%s#\n", myvar );
//
//	return 0;
//}



#include <stdio.h>
#include <string.h>


#define BUFFER       220
#define MAX_FIELDS   18
#define SYSTEMS   2



typedef enum
{
	STR = 1,
	HEX = 2,
	INT = 4
}
datatype ;


struct _field
{
	int   pos;
	int   size;
	datatype type ;
};


struct _header
{
	char  system[20];
	struct _field data [ MAX_FIELDS ];
};





const struct _header headers [ SYSTEMS ] =
{
	{
		"Megadrive",
		{
			{ 0x100, 16, STR }, // Console Name
			{ 0x110, 16, STR }, // Copyright Information
			{ 0x120, 48, STR }, // Domestic Name
			{ 0x150, 48, STR }, // Overseas Name
			{ 0x180, 14, STR }, // Serial Number
			{ 0x18E,  2, HEX }, // Checksum (2)
			{ 0x190, 16, STR }, // I/O Support (16)
			{ 0x1A0,  4, HEX }, // ROM Start Address (4)
			{ 0x1A4,  4, HEX }, // ROM End Address (4)
			{ 0x1A8,  4, HEX }, // Start of Backup RAM (4)
			{ 0x1AC,  4, HEX }, // End of Backup RAM (4)
			{ 0x1B0,  2, STR }, // "RA" for save ram (2)
			{ 0x1B2,  2, HEX }, // 0xF820 for save ram on odd bytes (2)
			{ 0x1B4,  4, HEX }, // SRAM start address - normally 0x200001 (4)
			{ 0x1B8,  4, HEX }, // SRAM end address - start + 2*sram_size (4)
			{ 0x1BC, 12, STR }, // Modem Support (24)
			{ 0x1C8, 40, STR }, // Memo (40)
			{ 0x1F0, 16, STR }, // Country Support (16)
		},
	},

	{
		"Master System",
		{
			{ 0x1B2,  2, HEX }, // 0xF820 for save ram on odd bytes (2)
			{ 0x1B4,  4, HEX }, // SRAM start address - normally 0x200001 (4)
			{ 0x1B8,  4, HEX }, // SRAM end address - start + 2*sram_size (4)
			{ 0x1BC, 12, STR }, // Modem Support (24)
			{ 0x1C8, 40, STR }, // Memo (40)
			{ 0x1F0, 16, STR }, // Country Support (16)
		}
	}
};



copiar ()
{
	FILE *f1 = fopen ( "rom.0.bin", "rb" );
	FILE *f2 = fopen ( "rom.bin", "wb" );

	fseek ( f1, 0, SEEK_END );
	int pos = ftell ( f1 );
	char str [ 1024 * 1024 ];

	fseek ( f1, 0, SEEK_SET );
	fseek ( f2, 0, SEEK_SET );

	fread  ( str, sizeof(char), pos, f1 );
	fwrite ( str, sizeof(char), pos, f2 );

	fclose ( f1 );
	fclose ( f2 );
}



void fill_head_var ( FILE *f )
{

//	int i, j;
//
//	fseek ( f, 0, SEEK_SET );
//
//	for ( i=0; i<FIELDS; i++ )
//	{
//		fgets ( head[i].data, BUFFER, f );
//
//		char chr  = ' ';
//		int  len  = strlen ( head[i].data ) - 1;
//		int  size = head[i].size;
//
//		if ( head[i].hex )  // is hexadecimal
//		{
//			chr  = '0';
//			size = size * 2 + 2;
//		}
//
//		for ( j=len; j<size; j++ )
//		{
//			head[i].data[j] = chr;
//		}
//
//		head[i].data[size] = '\0';
//	}

}



void rewrite_rom ( FILE *f )
{

//	int i, j;
//
//	fseek ( f, 256, SEEK_SET );
//
//	for ( i=0; i<FIELDS; i++ )
//	{
//		if ( head[i].hex )
//		{
//			for ( j=0; j<head[i].size; j++ )
//			{
//				char str[3] = { head[i].data[2+j*2+0], head[i].data[2+j*2+1] };
//				int val = strtoul ( str, NULL, 16 );
//
//				putc ( val, f );
//			}
//		}
//		else
//		{
//			fwrite ( head[i].data, sizeof(char),head[i].size, f );
//		}
//	}

}





void fix_checksum ( FILE *f )
{
	unsigned int checksum = 0;

	fseek ( f, 0x0200, SEEK_SET );

	while ( ! feof ( f ) )
	{
		int val;

		val = getc ( f ) * 256 ;
		checksum += val;

		val = getc ( f ) ;
		checksum += val;;
	}

	//checksum = checksum << 16;
	printf( "\%d", checksum >> 8 );
}



// ok
void fix_rom_size ( FILE *f )
{
	fseek ( f, 0, SEEK_END );
	int i, size = ftell ( f ) - 1 ;

	fseek ( f, 0x1A4, SEEK_SET );

	char hex[255] = {'\0'};
	sprintf ( hex, "%08X", size );

	for ( i=0; i<4; i++ )
	{
		char str[3] = { hex[i*2+0], hex[i*2+1] };
		int val = strtoul ( str, NULL, 16 );

		putc ( val, f );
	}
}


// ok
long fsize ( FILE *f )
{
	long size, pos = ftell ( f );

	fseek ( f, 0, SEEK_END );
	size = ftell ( f ) - 1 ;

	fseek ( f, pos, SEEK_SET );

	return size;
}


// ok
void write ( FILE *f, struct _field data, char *string )
{
	fseek ( f, data.pos, SEEK_SET );

	if ( data.type == HEX )
	{
		int i;

		for ( i=0; i<data.size; i++ )
		{
			char str[3] = { string [ 2+i*2+0 ], string [ 2+i*2+1 ] };
			int val = strtoul ( str, NULL, 16 );

			putc ( val, f );
		}
	}

	if ( data.type == STR )
	{
		fwrite ( string, sizeof(char), data.size, f );
	}
}


// ok
char *read ( FILE *f, struct _field data, int line )
{
	int i,j ;
	char aux[256];

	fseek ( f, 0, SEEK_SET );

	for ( i=0; i<=line; i++ )
	{
		fgets ( (char*)&aux, BUFFER, f );
	}

	char chr  = ' ';
	int  len  = strlen ( aux ) - 1;
	int  size = data.size;

	if ( data.type == HEX )
	{
		chr  = '0';
		size = size * 2 + 2;
	}

	for ( j=len; j<size; j++ )
	{
		aux[j] = chr;
	}

	aux[size] = '\0';

	return aux;
}


int main ( int argc, char** argv )
{

	//copiar ();

	// TODO - incluir info sobre los parametos
	// TODO - incluir info sobre lo que hace
	// TODO - incluir el fix_checksum a peticion
	// TODO - incluir posibilidad de añadir nº de comilación y fecha
	// TODO - distintos sistemas

	FILE *fRead  = fopen ( argv[1], "r+" );
	FILE *fWrite = fopen ( argv[2], "r+" );

	printf ( "%s", headers[0].system );

	//char *aux = read ( fData, headers[0].data, 1 );
//	puts(aux);


//	fill_head_var ( fData ) ;
//	rewrite_rom   ( fRom ) ;
//	//fix_checksum  ( f2 ) ;
//	fix_rom_size  ( fRom ) ;


	fclose ( fWrite );
	fclose ( fRead );

	return 0;
}



*/
