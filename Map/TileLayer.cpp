#include "TileLayer.h"
#include "TextureManager.h"
#include <iostream>

TileLayer::TileLayer(int tilesize, int colcount, int rowcount, TileMap tilemap, TilesetList tilesets):
m_TileSize(tilesize), m_ColCount(colcount), m_RowCount(rowcount), m_Tilemap(tilemap), m_Tilesets(tilesets)
{
//    m_TileSize = tilesize;
//    m_RownCount = rowcount;
//    m_ColCount = colcount;
//    m_Tilemap = tilemap;
//    m_Tilesets = tileset;

    for(unsigned int i=0; i < m_Tilesets.size(); i++)
    {
        TextureManager::GetInstance()->Load(m_Tilesets[i].Name, "assets/maps/" + m_Tilesets[i].Source);
        std::cout << "Name " << m_Tilesets[i].Name << " address: assets/maps/" + m_Tilesets[i].Source << std::endl;
    }


}

void TileLayer::Render()
{
    for(unsigned int i=0; i < m_RowCount; i++)
    {
                //std::cout << "i" << i << std::endl;
        for(unsigned int j=0; j < m_ColCount; j++)
        {
            //std::cout << "j " << j << std::endl;
            int tileID = m_Tilemap[i][j];

            if(tileID == 0)
                continue;
            else
            {
                int index = 0;
                if(m_Tilesets.size() > 1)
                {
                    for(unsigned int k = 1; k < m_Tilesets.size(); k++)
                    {
                        if( (tileID >= m_Tilesets[k].FirstID) && (tileID <= m_Tilesets[k].LastID))
                        {
                            tileID = tileID + m_Tilesets[k].TileCount - m_Tilesets[k].LastID;
                            index = k;
                            break;
                        }
                    }
                }


                Tileset ts = m_Tilesets[index];


                int tileRow = tileID / ts.ColCount;

                int tileCol = tileID - tileRow * ts.ColCount - 1;

                //std::cout << "tileID: " << tileID << std::endl;
                //std::cout << "ts.ColCount: " << ts.ColCount << std::endl;
                // If this tile is on the last column
                if(tileID % ts.ColCount == 0)
                {
                    tileRow--;
                    tileCol = ts.ColCount - 1 ;
                }


                TextureManager::GetInstance()->DrawTile(ts.Name, ts.TileSize, j*ts.TileSize, i*ts.TileSize, tileRow, tileCol);
            }

        }
    }
}

void TileLayer::Update()
{

}
