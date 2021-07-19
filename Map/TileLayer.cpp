#include "TileLayer.h"

TileLayer::TileLayer(int tilesize, int rowcount, int colcount, TileMap tilemap, TilesetList tileset)
{
    m_TileSize = tilesize;
    m_RownCount = rowcount;
    m_ColCount = colcount;
    m_Tilemap = tilemap;
    m_Tilesets = tileset;

}

void TileLayer::Render()
{

}

void TileLayer::Update()
{

}
