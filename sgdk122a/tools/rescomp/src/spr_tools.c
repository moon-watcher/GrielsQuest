#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

#include "../inc/spr_tools.h"
#include "../inc/tools.h"

static int getMaxNumTileAnimation(animation_* animation);
static int getMaxNumSpriteAnimation(animation_* animation);


frameSprite_* getFrameSprite(unsigned char *image8bpp, tileset_* tileset, int wi, int x, int y, int w, int h)
{
    int i, j;
    int pal, p;
    int index;
    unsigned int tile[8];
    frameSprite_* result;

    // get palette for this VDP sprite
    pal = getTile(image8bpp, tile, x, y, wi * 8);
    // error retrieving palette --> return NULL
    if (pal == -1) return NULL;

    for(i = 0; i < w; i++)
    {
        for(j = 0; j < h; j++)
        {
            p = getTile(image8bpp, tile, i + x, j + y, wi * 8);

            // error retrieving tile --> return NULL
            if (p == -1)
                return NULL;
            // different palette in VDP same sprite --> error
            if (p != pal)
            {
                printf("Error: Sprite at position (%d,%d) of size [%d,%d] use a different palette.", x, y, w, h);
                return NULL;
            }

            index = addTile(tile, tileset, FALSE, TILE_MAX_NUM);
            // error adding new tile --> return NULL
            if (index == -1)
                return NULL;
        }
    }

    // allocate result
    result = malloc(sizeof(frameSprite_));
    // initialized afterward
    result->x = 0;
	result->y = 0;
    result->w = w;
    result->h = h;
    result->numTile = w * h;

    return result;
}

animFrame_* getAnimFrame(unsigned char *image8bpp, int wi, int fx, int fy, int wf, int hf, int time, int collisionType)
{
    int i, j;
    int nbSprW, nbSprH;
    int lastSprW, lastSprH;
    int ws, hs;
    animFrame_* result;
    frameSprite_** frameSprites;
    frameSprite_* frameSprite;
    collision_* collision;
    tileset_* tileset;

    nbSprW = (wf + 3) / 4;
    nbSprH = (hf + 3) / 4;
    lastSprW = wf & 3;
    if (lastSprW == 0) lastSprW = 4;
    lastSprH = hf & 3;
    if (lastSprH == 0) lastSprH = 4;

    // allocate tileset
    tileset = createTileSet(malloc(wf * hf * 32), 0);

    // allocate result
    result = malloc(sizeof(animFrame_));
    result->numSprite = nbSprW * nbSprH;

    // allocate frameSprite array
    frameSprites = malloc(result->numSprite * sizeof(frameSprite_*));

    result->frameSprites = frameSprites;
    result->tileset = tileset;
	result->w = wf;
	result->h = hf;
    result->timer = time;

    if (collisionType == COLLISION_NONE)
    {
        result->numCollision = 0;
        result->collisions = NULL;
    }
    else
    {
        result->numCollision = 1;
        // allocate collision array
        result->collisions = malloc(1 * sizeof(collision_*));
        // allocate collision structure
        collision = malloc(sizeof(collision_));
        result->collisions[0] = collision;

        switch(collisionType)
        {
            case COLLISION_BOX:
                // use 75% the size of the frame for the collision
                collision->box.x = (wf * 8) / (4 * 2);
                collision->box.y = (hf * 8) / (4 * 2);
                collision->box.w = ((wf * 8) * 3) / 4;
                collision->box.h = ((hf * 8) * 3) / 4;
            break;

            case COLLISION_CIRCLE:
                // use 75% the size of the frame for the collision
                collision->circle.x = (wf * 8) / 2;
                collision->circle.y = (hf * 8) / 2;
                collision->circle.ray = ((wf * 8) * 3) / 8;
            break;
        }
    }

    for(j = 0; j < nbSprH; j++)
    {
        if (j == (nbSprH - 1)) hs = lastSprH;
        else hs = 4;

        for(i = 0; i < nbSprW; i++)
        {
            if (i == (nbSprW - 1)) ws = lastSprW;
            else ws = 4;

            frameSprite = getFrameSprite(image8bpp, tileset, wi, (fx * wf) + (i * 4), (fy * hf) + (j * 4), ws, hs);
            if (frameSprite == NULL)
                return NULL;

            // set x and y offset
            frameSprite->x = i * 32;
            frameSprite->y = j * 32;
            *frameSprites++ = frameSprite;
        }
    }

    return result;
}

animation_* getAnimation(unsigned char *image8bpp, int wi, int anim, int wf, int hf, int time, int collision)
{
    int i;
    animation_* result;
    animFrame_** frames;
    unsigned char* sequence;
    int numFrame;

    // get max number of frame
    numFrame = wi / wf;

    // allocate result
    result = malloc(sizeof(animation_));
    result->numFrame = numFrame;
    // allocate animFrame array
    frames = malloc(numFrame * sizeof(animFrame_*));
    result->frames = frames;
    // default sequence
	result->length = numFrame;
    // allocate sequence
    sequence = malloc(numFrame * sizeof(unsigned char));
    result->sequence = sequence;
    // default: loop to frame 0
    result->loop = 0;

    for(i = 0; i < numFrame; i++)
    {
        *frames = getAnimFrame(image8bpp, wi, i, anim, wf, hf, time, collision);
        if (*frames == NULL) return NULL;
        frames++;
        *sequence++ = i;
    }

    return result;
}

spriteDefinition_* getSpriteDefinition(unsigned char *image8bpp, int w, int h, int wf, int hf, int time, int collision)
{
    int i;
    int numAnim;
    spriteDefinition_* result;
    animation_** animations;

    // get number of animation
    numAnim = h / hf;

    // allocate result
    result = malloc(sizeof(spriteDefinition_));
    result->numAnimation = numAnim;
    // allocate animation array
    animations = malloc(numAnim * sizeof(animation_*));
    result->animations = animations;
    result->maxNumTile = 0;
    result->maxNumSprite = 0;

    for(i = 0; i < numAnim; i++)
    {
        *animations = getAnimation(image8bpp, w, i, wf, hf, time, collision);
        if (*animations == NULL) return NULL;

        // update maximum number of tile and sprite
        result->maxNumTile = MAX(result->maxNumTile, getMaxNumTileAnimation(*animations));
        result->maxNumSprite = MAX(result->maxNumSprite, getMaxNumSpriteAnimation(*animations));

        animations++;
    }

    return result;
}


static int getMaxNumTileAnimation(animation_* animation)
{
    int i;
    int result;
    animFrame_** frames;

    result = 0;
    frames = animation->frames;
    for(i = 0; i < animation->numFrame; i++)
    {
        result = MAX(result, (*frames)->tileset->num);
        frames++;
    }

    return result;
}

static int getMaxNumSpriteAnimation(animation_* animation)
{
    int i;
    int result;
    animFrame_** frames;

    result = 0;
    frames = animation->frames;
    for(i = 0; i < animation->numFrame; i++)
    {
        result = MAX(result, (*frames)->numSprite);
        frames++;
    }

    return result;
}


int packSpriteDef(spriteDefinition_ *spriteDef, int method)
{
    int i, j;
    int result;
    animFrame_ **animFrames;
    animation_ **animations;
    animFrame_ *animFrame;
    animation_ *animation;

    result = TRUE;

    animations = spriteDef->animations;

    for(i = 0; i < spriteDef->numAnimation; i++)
    {
        animation = *animations++;
        animFrames = animation->frames;

        for(j = 0; j < animation->numFrame; j++)
        {
            int m = method;

            animFrame = *animFrames++;
            if (!packTileSet(animFrame->tileset, &m)) result = FALSE;
        }
    }

    return result;
}

void removeEmptyFrame(spriteDefinition_ *spriteDef)
{
    int i, j;
    animFrame_ **animFrames;
    animation_ **animations;
    animation_ *animation;

    animations = spriteDef->animations;

    for(i = 0; i < spriteDef->numAnimation; i++)
    {
        animation = *animations++;
        animFrames = animation->frames;

        j = animation->numFrame - 1;
        // we force at least 1 frame (even if empty)
        while((j > 0) && isEmptyFrame(animFrames[j])) j--;

        // adjust number of frame
        animation->numFrame = j + 1;
        animation->length = j + 1;
    }
}

int isEmptyTileData(unsigned int *tiles, int numTiles)
{
    int i;
    unsigned int *tile;

    i = numTiles * 8;
    tile = tiles;
    while(i--)
    {
        if (*tile++) return FALSE;
    }

    return TRUE;
}

int isEmptyTileSet(tileset_ *tileset)
{
    return isEmptyTileData(tileset->tiles, tileset->num);
}

int isEmptyFrame(animFrame_ *animFrame)
{
    return isEmptyTileSet(animFrame->tileset);
}
