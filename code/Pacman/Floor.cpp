#include "Floor.h"


Floor::Floor(D3DXVECTOR3 *startPos, D3DXVECTOR2 dimensions)
{

	D3DXMatrixIdentity(&mWorld);

	model = new Model("Floor");

	vector<PolygonGroup> *poly = model->getGroups();

	poly->push_back(PolygonGroup("default"));

	PolygonGroup *group = &poly->back();

	group->material = new Material("floor material");


	//first triangle
	D3DXVECTOR3 *normal = new D3DXVECTOR3(0, 1, 0);
	D3DXVECTOR3 *pos = startPos;
	D3DXVECTOR2 *texC = new D3DXVECTOR2(0, 0);

	group->feedData(pos, texC, normal);
	
	pos->z = dimensions.y;
	texC->y = dimensions.y / 10;
	group->feedData(pos, texC, normal);

	pos->x = dimensions.x;
	texC->x = dimensions.x / 10;
	group->feedData(pos, texC, normal);
	
	//second triangle
	pos->x = pos->z = 0;
	texC->x = texC->y = 0;
	group->feedData(pos, texC, normal);

	pos->x = dimensions.x;
	pos->z = dimensions.y;
	texC->x = dimensions.x / 10;
	texC->y = dimensions.y / 10;
	group->feedData(pos, texC, normal);

	pos->z = 0;
	texC->y = 0;
	group->feedData(pos, texC, normal);
	
	SAFE_DELETE(normal);
	SAFE_DELETE(pos);
	SAFE_DELETE(texC);

	group->material->setTexture("sda");
	
	model->loadImageData();
	model->feedData();
	model->createBuffer();

}

void Floor::draw()
{
	GraphicsManager::getInstance()->useWorldMatrix(mWorld);
	model->draw(GraphicsManager::getInstance()->g_pTechRender);
}

Floor::~Floor()
{
	SAFE_DELETE( model );
}