#ifndef GENRES_H_
#define GENRES_H_

/****
History
18/10/28	
16/02/01	add PSG frame info
15/12/01	update for GenRes 2.0
14/07/25	more tiles possible for genresSpritesheet
14/07/11	added genresSpritesheet.collidebox for future use
			added animInfo.frameCount
14/07/10	updated genresMap
			removed genresAnimation
			added genresSpritesheet
14/06/30	renamed gensControl struct and members
14/06/28	fixed genresControlKey_t.ID
14/06/27	fixed genresAnim_t.nbTiles
			added some comments
			added genresControlxxx
xx/xx/xx	initial version
*****/


//TILES
struct genresTiles
{
	u16 *pal; 		//pointer to pal data
	u32 *tiles;		//pointer to tiles data
	u16 width;		//width in tiles
	u16 height;		//height in tiles
	u16 compressedSize;
};
typedef struct genresTiles genresTiles_t;

//HIRES
struct genresHires
{
	u16 width;		//width in tiles
	u16 height;		//height in tiles
	
	u16 *pal1; 		//pointer to pal data
	u16 *pal2;
	
	u32 *tiles1;		//pointer to tiles data
	u32 *tiles2;	

	u16 compressedSize1; 
	u16 compressedSize2; 
};
typedef struct genresHires genresHires_t;

//SPRITES
struct genresSprites
{
	u16 *pal; 		//pointer to pal data
	u32 **sprites;		//pointer to sprites data
	u16 count;		//nb sprites
	u16 width;		//width of each sprite in pixels
	u16 height;		//height of each sprite in pixels
	u8  size; 		//since we use width/height in pixel, useful info on sprite size
					//SGDK compliant, use it in VDP_setSpriteXXX
};
typedef struct genresSprites genresSprites_t;

//SPRITESHEET
struct animInfo {
	u8	frameRate;
	u8 	frameCount;
	u8	frames[1 /* n frame index */];
};
struct collideBox {
	u8	top;
	u8 	left;
	u8	bottom;
	u8	right;
};

//an animation is made of several frames of the same size
//a frame 	is a big sprite made of n sequential sprites
//			could be used by several animations
//a sprite	is 32pixels width/height max
//			is made of tiles
struct genresSpritesheet {
	u16 nbAnimations;
	
	//u16 nbFrames; //unneeded
	//u16 nbSprites;//unneeded

	u8 frameSpriteH; 	//nb sprite horizontal
	u8 frameSpriteV; 	//nb sprite vertical
						//to draw sub sprites one by one
						
	u8	frameWidth; //width in pixel of a frame
	u8	frameHeight;//height
					//to test collide
	
	u16 frameTiles; 	//nb tiles needed for a frame
					//to know how many tile to load on update frame
	
	u8 spriteSize; //SGDK compliant unique sprite size
	u8 padding;
	
	u16	*pal;
	struct animInfo **animations;
	
	u16 ***frames;		//pointer to frame (frameTiles tiles)
	//to draw a frame, 	load frameTiles to VDP from tiles + frameIdx*frameTiles
	//					draw frameSpriteV*frameSpriteH sprites (only the first time, since updating VDP will reflect the change afterwards)
	struct collideBox **collideBoxes; //soon
};
typedef struct genresSpritesheet genresSpritesheet_t;

//PAL
//typedef u16	genresPal[16];
struct genresPal {
	u16 colors[16];
};
typedef struct genresPal genresPal_t;

//MAP
struct genresMap{
	//map size
	u16	width;
	u16	height;
	
	//pal
	u16	*pal;

	//tiles	
	u16	nbTiles; //number of tiles used
	u16	compSize; //0 if not compressed
	u32	*tiles; //pointer to tiles data
	
	//layers
	u16	nbLayers;
	u16	**layers; //pointer to layers data
};
typedef struct genresMap genresMap_t;


//CONTROLS
struct genresControlSequence{
	u16	ID;
	u16	keys[1]; //array of keys, finished by zero
};
typedef struct genresControlSequence genresControlSequence_t;

struct genresControl{
	u16	nbSequences;
	genresControlSequence_t	**sequences; //pointer to map data
};
typedef struct genresControl genresControl_t;


//PSG
struct genresPSGFrame
{
	u8 mixer;	//llllnccc  l = loop (how many update use the same frame)
				//			n = noise enabled
				//			c = channels (1 bit per channel)
				//00000000 means end of sounds
	u8 noise;
	struct channel{
        u8 volume;
        u8 toneLatch;
        u8 toneData;
	}channels[3]; //values ready to be send to PSG port
};
typedef struct genresPSGFrame genresPSGFrame_t;

#endif /* GENRES_H_ */
