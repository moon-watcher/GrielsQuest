typedef struct
{
	struct genresSprites *res; // el recurso

	u8 width;   // nº sprites ancho
	u8 height;  // nº sprites alto

	s16 vrampos; // posicion en la memoria

	u8 first_sprite;
}
SPRITESET;



void spriteset_new     ( SPRITESET *set, struct genresSprites *res, u8 width, u8 height );
void spriteset_load    ( SPRITESET *set, u16 vrampos, u16 dma );
void spriteset_show    ( SPRITESET *set, u8 sprite, s16 pos_x, s16 pos_y, u16 tile_attr );
void spriteset_move    ( SPRITESET *set, s16 pos_x, s16 pos_y );
u16  spriteset_tiles   ( SPRITESET *set );
u16  spriteset_sprites ( SPRITESET *set );
