#include "game.h"
#include "gameobject.h"
#include "texturemanager.h"
#include "map.h"
#include <cstdlib>
#include <cmath>
using namespace std;
int gx;
int gy;
int px;
int py;
int cx;
int cy;
int gover=0;
int fin=0;
int cch=0;
int tes=0;
int ugl=1;
int star=0;
static int cntt=0;
static int s=1;
static int v=2;
static int u=4;
static int uup=0;
static int ddo=0;
static int lle=0;
static int rri=0;
static int cup;
static int cdo;
static int cle;
static int cri;
static int nup;
static int ndo;
static int nle;
static int nri;
static int kee=0;
static int acc=1;
int ggov()
{
	if(gover!=1)
	{
		return 0;	
	}
	uup=0;
	ddo=0;
	lle=0;
	rri=0;
	return 1;
}
int finn()
{
	if(fin!=1)
	{
		return 0;	
	}
	return 1;
}
GameObject::GameObject(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpos=x;
	ypos=y;
}
void GameObject::Update()
{
	
	if(gover==1)
	{
		xpos=800;
		ypos=800;
	}
	int lvl1[20][25]=
	{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0},
	{0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,1,0},
	{0,1,0,1,1,0,2,2,2,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,0},
	{0,1,1,1,0,2,2,0,2,2,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0},
	{0,1,0,0,0,2,0,0,0,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,0},
	{0,1,1,1,0,2,2,0,2,2,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0},
	{0,1,0,1,1,0,2,2,2,0,0,0,2,2,2,2,2,0,0,0,1,0,0,1,0},
	{0,1,0,0,1,0,0,0,1,1,1,1,2,0,0,0,2,1,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,1,0,0,0,0,0,2,2,2,2,2,0,1,1,0,1,1,1,0},
	{0,1,0,0,1,0,1,0,1,1,1,1,2,0,0,1,0,0,0,1,0,0,0,1,0},
	{0,1,1,0,1,0,1,0,1,0,0,0,2,0,1,1,1,0,1,1,0,1,1,1,0},
	{0,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,2,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,0,1,0,0,1,0,0,0,1,0,0,2,0,0,1,0,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,0,2,1,1,1,1,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,2,0,0,0,1,0,1,0},
	{0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	if(cntt>=1000&&gover==0)
	{
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
	if(gover==0)
	{
		if(ugl==3&&xpos%32==0&&ypos%32==0&&cntt>=2400)
		{
			cout<<"Warning:red clouds become very very fast!!"<<endl;
			acc=4;
			ugl=4;
		}
		else if(ugl==1&&xpos%32==0&&ypos%32==0&&cntt>=800)
		{
			cout<<"Warning:red clouds become more faster!!"<<endl;
			acc=2;
			ugl=2;
		}	
	}
	int t=xpos;
	int r=ypos;
	if(ugl==2&&cntt>=1600)
	{
		ugl=3;
		cout<<"Warning:From now on,red clouds will chase you if you are close enough to them!!"<<endl; 
	}
	star=star+1;
	if(star>400)
	{
	if(cntt>=1600)
	{
		if(xpos==px&&ypos-py<=96&&ypos>py)
		{
			if(lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
			{
				ypos=ypos-s*acc;
				i=3;
			}
			else if(lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
			{
				xpos=xpos+s*acc;
				i=0;
			}
			else if(lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
			{
				xpos=xpos-s*acc;
				i=2;
			}
		}
		else if(ypos==py&&xpos-px<=96&&xpos>px)
		{
			if(lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
			{
				xpos=xpos-s*acc;
				i=2;
			}
			else if(lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
			{
				ypos=ypos-s*acc;
				i=3;
			}
			else if(lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
			{
				ypos=ypos+s*acc;
				i=1;
			}
		}
		else if(xpos==px&&py-ypos<=96&&ypos<py)
		{
			if(lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
			{
				ypos=ypos+s*acc;
				i=1;
			}
			else if(lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
			{
				xpos=xpos+s*acc;
				i=0;
			}
			else if(lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
			{
				xpos=xpos-s*acc;
				i=2;
			}
		}
		else if(ypos==py&&px-xpos<=96&&xpos<px)
		{
			if(lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
			{
				xpos=xpos+s*acc;
				i=0;
			}
			else if(lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
			{
				ypos=ypos-s*acc;
				i=3;
			}
			else if(lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
			{
				ypos=ypos+s*acc;
				i=1;
			}
		}
		else if(xpos-px<=48&&xpos>px&&ypos-py<=48&&ypos>py)
		{
			if(xpos-px>=ypos-py&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
			{
				ypos=ypos-s*acc;
				i=3;
			}
			if(xpos-px<ypos-py&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
			{
				xpos=xpos-s*acc;
				i=2;
			}
		}
		else if(px-xpos<=48&&xpos<px&&ypos-py<=48&&ypos>py)
		{
			if(px-xpos>=ypos-py&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
			{
				ypos=ypos-s*acc;
				i=3;
			}
			if(px-xpos<ypos-py&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
			{
				xpos=xpos+s*acc;
				i=0;
			}
		}
		else if(px-xpos<=48&&xpos<px&&py-ypos<=48&&ypos<py)
		{
			if(px-xpos>=py-ypos&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
			{
				ypos=ypos+s*acc;
				i=1;
			}
			if(px-xpos<py-ypos&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
			{
				xpos=xpos+s*acc;
				i=0;
			}
		}
		else if(xpos-px<=48&&xpos>px&&py-ypos<=48&&ypos<py)
		{
			if(xpos-px>=py-ypos&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
			{
				ypos=ypos+s*acc;
				i=1;
			}
			if(xpos-px>=py-ypos&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
			{
				xpos=xpos-s*acc;
				i=2;
			}
		}
	}
	if(t==xpos&&r==ypos)
	{
		while(gover==0&&t==xpos&&r==ypos)
		{
			det=5;
			int tt=rand()%10+3;
			int dn=tt%4;
			switch(dn)
			{
			case 0:
				if(i!=2&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
				{
					xpos=xpos+s*acc;
					i=0;
					break;
				}
			case 1:
				if(i!=3&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
				{
					ypos=ypos+s*acc;
					i=1;
					break;
				}
			case 2:
				if(i!=0&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
				{
					xpos=xpos-s*acc;
					i=2;
					break;
				}
			case 3:
				if(i!=1&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
				{
					ypos=ypos-s*acc;
					i=3;
					break;
				}
			default:
				{
					break;	
				}		
			}
		}
	}
	if(acc==4&&xpos%4==2)
	{
		if(xpos%32==2)
		{
			xpos=xpos-2;
		}
		if(xpos%32==30)
		{
			xpos=xpos+2;
		}
	}
	if(acc==4&&ypos%4==2)
	{
		if(ypos%32==2)
		{
			ypos=ypos-2;
		}
		if(ypos%32==30)
		{
			ypos=ypos+2;
		}
	}
	if(acc==2&&xpos%2==1)
	{
		if(xpos%32==1)
		{
			xpos=xpos-1;
		}
		if(xpos%32==31)
		{
			xpos=xpos+1;
		}
	}
	if(acc==2&&ypos%2==1)
	{
		if(ypos%32==1)
		{
			ypos=ypos-1;
		}
		if(ypos%32==31)
		{
			ypos=ypos+1;
		}
	}
	}
	det=0;
	gx=xpos;
	gy=ypos;
	srcRect.h=32;
	srcRect.w=32;
	srcRect.x=0;
	srcRect.y=0;
	
	destRect.x=xpos;
	destRect.y=ypos;
	destRect.w=srcRect.w;
	destRect.h=srcRect.h;
	if(t<800)
	{
		dead();
	}
	
}
void GameObject::dead()
{
	if((gx-px<32&&px-gx<32&&gy==py)||(gy-py<32&&py-gy<32&&px==gx))
	{
//		gameover();
	}
}
void GameObject::gameover()
{
	if(gover==0)
	{
		cout<<"Gameover!"<<endl;
	}
	gover=1;
}
void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}

Ghost::Ghost(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpos=x;
	ypos=y;
}
void Ghost::Update()
{
	
	if(gover==1)
	{
		xpos=800;
		ypos=800;
	}
	int lvl1[20][25]=
	{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0},
	{0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,1,0},
	{0,1,0,1,1,0,2,2,2,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,0},
	{0,1,1,1,0,2,2,0,2,2,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0},
	{0,1,0,0,0,2,0,0,0,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,0},
	{0,1,1,1,0,2,2,0,2,2,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0},
	{0,1,0,1,1,0,2,2,2,0,0,0,2,2,2,2,2,0,0,0,1,0,0,1,0},
	{0,1,0,0,1,0,0,0,1,1,1,1,2,0,0,0,2,1,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,1,0,0,0,0,0,2,2,2,2,2,0,1,1,0,1,1,1,0},
	{0,1,0,0,1,0,1,0,1,1,1,1,2,0,0,1,0,0,0,1,0,0,0,1,0},
	{0,1,1,0,1,0,1,0,1,0,0,0,2,0,1,1,1,0,1,1,0,1,1,1,0},
	{0,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,2,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,0,1,0,0,1,0,0,0,1,0,0,2,0,0,1,0,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,0,2,1,1,1,1,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,2,0,0,0,1,0,1,0},
	{0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	if(cntt<10000)
	{
		cntt=cntt+1;
	}
	if(cntt==1000)
	{
		cout<<"Warning:crabs escape!!"<<endl;
	}
	if(cntt>=1000&&gover==0)
	{
		
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
	int t=xpos;
	int r=ypos;
	star=star+1;
	if(star>400)
	{
	while(cntt>=1000&&gover==0&&t==xpos&&r==ypos)
	{
		
		int tt=rand()%10+3;
		int dn=tt%4;
		switch(dn)
		{
		case 0:
			if(i!=2&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
			{
				xpos=xpos+u;
				i=0;
				break;
			}
		case 1:
			if(i!=3&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
			{
				ypos=ypos+u;
				i=1;
				break;
			}
		case 2:
			if(i!=0&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
			{
				xpos=xpos-u;
				i=2;
				break;
			}
		case 3:
			if(i!=1&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
			{
				ypos=ypos-u;
				i=3;
				break;
			}
		default:
			{
				break;	
			}		
		}	
	}
	}
	gx=xpos;
	gy=ypos;
	srcRect.h=32;
	srcRect.w=32;
	srcRect.x=0;
	srcRect.y=0;
	
	destRect.x=xpos;
	destRect.y=ypos;
	destRect.w=srcRect.w;
	destRect.h=srcRect.h;
	if(t<800)
	{
		dead();
	}
	
}
void Ghost::dead()
{
	if((gx-px<32&&px-gx<32&&gy==py)||(gy-py<32&&py-gy<32&&px==gx)) 
	{
		gameover();
	}
}
void Ghost::gameover()
{
	if(gover==0)
	{
		cout<<"Gameover!"<<endl;
	}
	gover=1;
}
void Ghost::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}

Player::Player(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpo=x;
	ypo=y;
}

static int dir=-1;
void Player::handleEvent( SDL_Event& e )
{
	
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:  
			uup = 1;
			nup = 1;
			break;
        case SDLK_DOWN: 
			ddo = 1;
			ndo = 1;  
			break;
        case SDLK_LEFT: 
			lle = 1;
			nle = 1;
			break;
        case SDLK_RIGHT: 
			rri = 1;
			nri = 1;
			break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:  
			uup = 0;
			nup = 0;
			cup=0; 
			break;
    	case SDLK_DOWN: 
			ddo = 0;
			ndo = 0;
			cdo=0; 
			break;
        case SDLK_LEFT: 
			lle = 0;
			nle = 0;
			cle=0; 
			break;
        case SDLK_RIGHT: 
			rri = 0;
			nri = 0;
			cri=0; 
			break;
        }
    }
}
void Player::Update()
{
	if(gover==1)
	{
		xpo=800;
		ypo=800;
	}
	if(uup == 1) 
	cup=cup+1; 
	if(ddo == 1)
	cdo=cdo+1; 
	if(lle == 1)
	cle=cle+1;
	if(rri == 1)
	cri=cri+1;
	int lvl1[20][25]=
	{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0},
	{0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,1,0},
	{0,1,0,1,1,0,2,2,2,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,0},
	{0,1,1,1,0,2,2,0,2,2,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0},
	{0,1,0,0,0,2,0,0,0,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,0},
	{0,1,1,1,0,2,2,0,2,2,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0},
	{0,1,0,1,1,0,2,2,2,0,0,0,2,2,2,2,2,0,0,0,1,0,0,1,0},
	{0,1,0,0,1,0,0,0,1,1,1,1,2,0,0,0,2,1,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,1,0,0,0,0,0,2,2,2,2,2,0,1,1,0,1,1,1,0},
	{0,1,0,0,1,0,1,0,1,1,1,1,2,0,0,1,0,0,0,1,0,0,0,1,0},
	{0,1,1,0,1,0,1,0,1,0,0,0,2,0,1,1,1,0,1,1,0,1,1,1,0},
	{0,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,2,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,0,1,0,0,1,0,0,0,1,0,0,2,0,0,1,0,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,0,2,1,1,1,1,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,2,0,0,0,1,0,1,0},
	{0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	if(cntt>=1000&&gover==0)
	{
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
	int iii=0;
	if(cri!=0)
	{
		iii=iii+1;
	}
	if(cle!=0)
	{
		iii=iii+1;
	}
	if(cdo!=0)
	{
		iii=iii+1;
	}
	if(cup!=0)
	{
		iii=iii+1;
	}
	
	int xyx=xpo;
	int yxy=ypo;
	star=star+1;
	if(star>400)
	{
	if(cup!=0&&cdo!=0&&cri!=0)
	{
		if(cup>=cdo&&cup>cri)
		{
			cup=0;
		}
		if(cdo>=cri&&cdo>cup)
		{
			cdo=0;
		}
		if(cri>=cup&&cri>cdo)
		{
			cri=0;
		}
	}
	if(cup!=0&&cdo!=0&&cle!=0)
	{
		if(cup>=cdo&&cup>cle)
		{
			cup=0;
		}
		if(cdo>=cle&&cdo>cup)
		{
			cdo=0;
		}
		if(cle>=cup&&cle>cdo)
		{
			cle=0;
		}
	}
	if(cle!=0&&cdo!=0&&cri!=0)
	{
		if(cle>=cdo&&cle>cri)
		{
			cle=0;
		}
		if(cdo>=cri&&cdo>cle)
		{
			cdo=0;
		}
		if(cri>=cle&&cri>cdo)
		{
			cri=0;
		}
	}
	if(cup!=0&&cri!=0&&cle!=0)
	{
		if(cup>=cri&&cup>cle)
		{
			cup=0;
		}
		if(cri>=cle&&cri>cup)
		{
			cri=0;
		}
		if(cle>=cup&&cle>cri)
		{
			cle=0;
		}
	}
	if((cup!=0&&cdo!=0)||(cri!=0&&cle!=0))
	{
		if(cup>cdo)
		{
			cup=0;
		}
		else if(cup<=cdo)
		{
			cdo=0;
		}
		if(cle>=cri)
		{
			cle=0;
		}
		else if(cle<cri)
		{
			cri=0;
		}
	}
	else if(cri!=0&&cdo!=0)
	{
		if(cri>cdo)
		{
			if((lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
			(lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
			{
				if(xpo%32==4)
				{
					xpo=xpo-4;
				}
				if(xpo%32==28)
				{
					xpo=xpo+4;
				}
				ypo=ypo+u;
				dir=1;
			}
			else if((lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
			(lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
			{
				if(ypo%32==4)
				{
					ypo=ypo-4;
				}
				if(ypo%32==28)
				{
					ypo=ypo+4;
				}
				xpo=xpo+u;
				dir=0;
			}
		}
		else if(cri<=cdo)
		{
			if((lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
			(lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
			{
				if(ypo%32==4)
				{
					ypo=ypo-4;
				}
				if(ypo%32==28)
				{
					ypo=ypo+4;
				}
				xpo=xpo+u;
				dir=0;
			}
			else if((lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
			(lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
			{
				if(xpo%32==4)
				{
					xpo=xpo-4;
				}
				if(xpo%32==28)
				{
					xpo=xpo+4;
				}
				ypo=ypo+u;
				dir=1;
			}
		}	
	}
	else if(cri!=0&&cup!=0)
	{
		if(cri>cup)
		{
			if((lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
			(lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
			{
				if(xpo%32==4)
				{
					xpo=xpo-4;
				}
				if(xpo%32==28)
				{
					xpo=xpo+4;
				}
				ypo=ypo-u;
				dir=3;
			}
			else if((lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
			(lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
			{
				if(ypo%32==4)
				{
					ypo=ypo-4;
				}
				if(ypo%32==28)
				{
					ypo=ypo+4;
				}
				xpo=xpo+u;
				dir=0;
			}
		}
		else if(cri<=cup)
		{
			if((lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
			(lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
			{
				if(ypo%32==4)
				{
					ypo=ypo-4;
				}
				if(ypo%32==28)
				{
					ypo=ypo+4;
				}
				xpo=xpo+u;
				dir=0;
			}
			else if((lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
			(lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
			{
				if(xpo%32==4)
				{
					xpo=xpo-4;
				}
				if(xpo%32==28)
				{
					xpo=xpo+4;
				}
				ypo=ypo-u;
				dir=3;
			}
		}	
	}
	else if(cle!=0&&cup!=0)
	{
		if(cle<=cup)
		{
			if((lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
			||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
			{
				if(ypo%32==4)
				{
					ypo=ypo-4;
				}
				if(ypo%32==28)
				{
					ypo=ypo+4;
				}
				xpo=xpo-u;
				dir=2;
			}
			else if((lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
			(lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
			{
				if(xpo%32==4)
				{
					xpo=xpo-4;
				}
				if(xpo%32==28)
				{
					xpo=xpo+4;
				}
				ypo=ypo-u;
				dir=3;
			}	
		}
		else if(cle>cup)
		{
			if((lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
			(lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
			{
				if(xpo%32==4)
				{
					xpo=xpo-4;
				}
				if(xpo%32==28)
				{
					xpo=xpo+4;
				}
				ypo=ypo-u;
				dir=3;
			}
			else if((lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
			||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
			{
				if(ypo%32==4)
				{
					ypo=ypo-4;
				}
				if(ypo%32==28)
				{
					ypo=ypo+4;
				}
				xpo=xpo-u;
				dir=2;
			}
		}	
	}
	else if(cle!=0&&cdo!=0)
	{
		if(cle<=cdo)
		{
			if((lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
			||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
			{
				if(ypo%32==4)
				{
					ypo=ypo-4;
				}
				if(ypo%32==28)
				{
					ypo=ypo+4;
				}
				xpo=xpo-u;
				dir=2;
			}
			else if((lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
			(lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
			{
				if(xpo%32==4)
				{
					xpo=xpo-4;
				}
				if(xpo%32==28)
				{
					xpo=xpo+4;
				}
				ypo=ypo+u;
				dir=1;
			}
		}	
		else if(cle>cdo)
		{
			if((lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
			(lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
			{
				if(xpo%32==4)
				{
					xpo=xpo-4;
				}
				if(xpo%32==28)
				{
					xpo=xpo+4;
				}
				ypo=ypo+u;
				dir=1;
			}
			else if((lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
			||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
			{
				if(ypo%32==4)
				{
					ypo=ypo-4;
				}
				if(ypo%32==28)
				{
					ypo=ypo+4;
				}
				xpo=xpo-u;
				dir=2;
			}	
		}	
	}
	else if(ggov()!=1)
	{
		if(((nri==1&&nle!=1)||cri!=0)&&(lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
			(lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
			{
				if(ypo%32==4)
				{
					ypo=ypo-4;
				}
				if(ypo%32==28)
				{
					ypo=ypo+4;
				}
				xpo=xpo+u;
				dir=0;
			}
		else if(((ndo==1&&nup!=1)||cdo!=0)&&(lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
			(lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
			{
				if(xpo%32==4)
				{
					xpo=xpo-4;
				}
				if(xpo%32==28)
				{
					xpo=xpo+4;
				}
				ypo=ypo+u;
				dir=1;
			}
		else if(((nle==1&&nri!=1)||cle!=0)&&(lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
			||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
			{
				if(ypo%32==4)
				{
					ypo=ypo-4;
				}
				if(ypo%32==28)
				{
					ypo=ypo+4;
				}
				xpo=xpo-u;
				dir=2;
			}
		else if(((nup==1&&ndo!=1)||cup!=0)&&(lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
			(lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
			{
				if(xpo%32==4)
				{
					xpo=xpo-4;
				}
				if(xpo%32==28)
				{
					xpo=xpo+4;
				}
				ypo=ypo-u;
				dir=3;
			}
	}
	if(xyx==xpo&&yxy==ypo)
	{
		if(ggov()!=1)
		{
			if(kee==0)
			{
				kee=5;
			}
			else if(xpo%32==0&&ypo%32==0&&kee>2)
			{
				kee=kee-1;
			}
			if(kee>3)
			{
				if(dir==0&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					xpo=xpo+u;
					dir=0;
				}
				else if(dir==1&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					ypo=ypo+u;
					dir=1;
				}
				else if(dir==2&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					xpo=xpo-u;
					dir=2;
				}
				else if(dir==3&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					ypo=ypo-u;
					dir=3;
				}	
			}
		}
	}	
	if(uup==1||ddo==1||rri==1||lle==1)
	{
		kee=0;
	}		
	}
	px=xpo;
	py=ypo;
    
    if (frame/4 == 0)
    {
        switch (dir)
        {
            case 3: // up
                srcRect.x = 0;
                srcRect.y = 96;
                break;
            case 1: // down
                srcRect.x = 0;
                srcRect.y = 0;
                break;
            case 2: //left
                srcRect.x = 0;
                srcRect.y = 32;
                break;
            case 0: // right
                srcRect.x = 0;
                srcRect.y = 64;
                break;
        }
    }
    if (frame/4 == 1)
    {
        switch (dir)
        {
            case 3: // up
                srcRect.x = 32;
                srcRect.y = 96;
                break;
            case 1: // down
                srcRect.x = 32;
                srcRect.y = 0;
                break;
            case 2: //left
                srcRect.x = 32;
                srcRect.y = 32;
                break;
            case 0: // right
                srcRect.x = 32;
                srcRect.y = 64;
                break;
        }
    }
    if (frame/4 == 2)
    {
        switch (dir)
        {
            case 3: // up
                srcRect.x = 64;
                srcRect.y = 96;
                break;
            case 1: // down
                srcRect.x = 64;
                srcRect.y = 0;
                break;
            case 2: //left
                srcRect.x = 64;
                srcRect.y = 32;
                break;
            case 0: // right
                srcRect.x = 64;
                srcRect.y = 64;
                break;
        }
    }
    srcRect.w = 32;
    srcRect.h = 32;
	
	destRect.x=xpo;
	destRect.y=ypo;
	destRect.w=srcRect.w;
	destRect.h=srcRect.h;
	
}

void Player::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}

Chi::Chi(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpo=x;
	ypo=y;
}
void Chi::Update()
{
	if(gover==1&&ypo<640)
	{
		xpo=800;
		ypo=800;
	}
	int lvl1[20][25]=
	{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0},
	{0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0},
	{0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,1,0},
	{0,1,0,1,1,0,2,2,2,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,0},
	{0,1,1,1,0,2,2,0,2,2,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0},
	{0,1,0,0,0,2,0,0,0,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,0},
	{0,1,1,1,0,2,2,0,2,2,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0},
	{0,1,0,1,1,0,2,2,2,0,0,0,2,2,2,2,2,0,0,0,1,0,0,1,0},
	{0,1,0,0,1,0,0,0,1,1,1,1,2,0,0,0,2,1,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,1,0,0,0,0,0,2,2,2,2,2,0,1,1,0,1,1,1,0},
	{0,1,0,0,1,0,1,0,1,1,1,1,2,0,0,1,0,0,0,1,0,0,0,1,0},
	{0,1,1,0,1,0,1,0,1,0,0,0,2,0,1,1,1,0,1,1,0,1,1,1,0},
	{0,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,2,1,0,1,1,0,1,0},
	{0,1,1,1,1,1,0,1,0,0,1,0,0,0,1,0,0,2,0,0,1,0,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,0,2,1,1,1,1,0,1,0},
	{0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,2,0,0,0,1,0,1,0},
	{0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	if(cntt>=1000&&gover==0)
	{
		lvl1[3][11]=1;
		lvl1[3][13]=1;
		lvl1[16][11]=1;
		lvl1[16][13]=1;
	}
	int t=xpo;
	int r=ypo;
	star=star+1;
	if(star>400)
	{
	if(r<640)
	{
		if(det<24)
		{
			if(xpo==px&&ypo-py<=96&&ypo>py)
			{
				if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					ypo=ypo+u;
					j=1;
					det=det+1;
				}
				else if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					xpo=xpo+u;
					j=0;
					det=det+1;
				}
				else if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					xpo=xpo-u;
					j=2;
					det=det+1;
				}
			}
			else if(ypo==py&&xpo-px<=96&&xpo>px)
			{
				if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					xpo=xpo+u;
					j=0;
					det=det+1;
				}
				else if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					ypo=ypo-u;
					j=3;
					det=det+1;
				}
				else if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					ypo=ypo+u;
					j=1;
					det=det+1;
				}
			}
			else if(xpo==px&&py-ypo<=96&&ypo<py)
			{
				if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					ypo=ypo-u;
					j=3;
					det=det+1;
				}
				else if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					xpo=xpo+u;
					j=0;
					det=det+1;
				}
				else if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					xpo=xpo-u;
					j=2;
					det=det+1;
				}
			}
			else if(ypo==py&&px-xpo<=96&&xpo<px)
			{
				if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					xpo=xpo-u;
					j=2;
					det=det+1;
				}
				else if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					ypo=ypo-u;
					j=3;
					det=det+1;
				}
				else if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					ypo=ypo+u;
					j=1;
					det=det+1;
				}
			}
			else if(xpo-px<=48&&xpo>px&&ypo-py<=48&&ypo>py)
			{
				if(xpo-px<=ypo-py&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					ypo=ypo+u;
					j=1;
					det=det+1;
				}
				if(xpo-px>ypo-py&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					xpo=xpo+u;
					j=0;
					det=det+1;
				}
			}
			else if(px-xpo<=48&&xpo<px&&ypo-py<=48&&ypo>py)
			{
				if(px-xpo<=ypo-py&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					ypo=ypo+u;
					j=1;
					det=det+1;
				}
				if(px-xpo>ypo-py&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					xpo=xpo-u;
					j=2;
					det=det+1;
				}
			}
			else if(px-xpo<=48&&xpo<px&&py-ypo<=48&&ypo<py)
			{
				if(px-xpo<=py-ypo&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					ypo=ypo-u;
					j=3;
					det=det+1;
				}
				if(px-xpo>py-ypo&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					xpo=xpo-u;
					j=2;
					det=det+1;
				}
			}
			else if(xpo-px<=48&&xpo>px&&py-ypo<=48&&ypo<py)
			{
				if(xpo-px<=py-ypo&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					ypo=ypo-u;
					j=3;
					det=det+1;
				}
				if(xpo-px>py-ypo&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					xpo=xpo+u;
					j=0;
					det=det+1;
				}
			}
			if(det>0)
			{
				if(xpo%32==2)
				{
					xpo=xpo-2;
				}
				if(xpo%32==30)
				{
					xpo=xpo+2;
				}
				if(ypo%32==2)
				{
					ypo=ypo-2;
				}
				if(ypo%32==30)
				{
					ypo=ypo+2;
				}
			}	
		}
		if(det>=24)
		{
			if(xpo==px&&ypo-py<=96&&ypo>py)
			{
				if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					ypo=ypo+v;
					j=1;
					det=det+1;
				}
			}
			else if(ypo==py&&xpo-px<=96&&xpo>px)
			{
				if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					xpo=xpo+v;
					j=0;
					det=det+1;
				}
			}
			else if(xpo==px&&py-ypo<=96&&ypo<py)
			{
				if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					ypo=ypo-v;
					j=3;
					det=det+1;
				}
			}
			else if(ypo==py&&px-xpo<=96&&xpo<px)
			{
				if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					xpo=xpo-v;
					j=2;
					det=det+1;
				}
			}
			else if(xpo-px<=48&&xpo>px&&ypo-py<=48&&ypo>py)
			{
				if(px-xpo>=py-ypo&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					ypo=ypo+v;
					j=1;
					det=det+1;
				}
				if(px-xpo<py-ypo&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					xpo=xpo+v;
					j=0;
					det=det+1;
				}
			}
			else if(px-xpo<=48&&xpo<px&&ypo-py<=48&&ypo>py)
			{
				if(xpo-px>=py-ypo&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
				{
					ypo=ypo+v;
					j=1;
					det=det+1;
				}
				if(xpo-px>=py-ypo&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					xpo=xpo-v;
					j=2;
					det=det+1;
				}
			}
			else if(px-xpo<=48&&xpo<px&&py-ypo<=48&&ypo<py)
			{
				if(xpo-px>=ypo-py&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					ypo=ypo-v;
					j=3;
					det=det+1;
				}
				if(xpo-px<ypo-py&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
				{
					xpo=xpo-v;
					j=2;
					det=det+1;
				}
			}
			else if(xpo-px<=48&&xpo>px&&py-ypo<=48&&ypo<py)
			{
				if(px-xpo>=ypo-py&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
				{
					ypo=ypo-v;
					j=3;
					det=det+1;
				}
				if(px-xpo<ypo-py&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
				{
					xpo=xpo+v;
					j=0;
					det=det+1;
				}
			}
		}	
		while(gover==0&&r<640&&t==xpo&&r==ypo)
		{
				det=0;
				int tt=rand()%10+3;
				int dn=tt%4;
				switch(dn)
				{
				case 0:
					if(j!=2&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
					{	
						xpo=xpo+v;
						j=0;
						break;
					}
				case 1:
					if(j!=3&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
					{
						ypo=ypo+v;
						j=1;
						break;
					}
				case 2:
					if(j!=0&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
					{
						xpo=xpo-v;
						j=2;
						break;
					}	
				case 3:
					if(j!=1&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
					{
						ypo=ypo-v;
						j=3;
						break;
					}
				default:
					{
						break;	
					}		
				}		
		}	
	}
	}
	cx=xpo;
	cy=ypo;
	srcRect.h=32;
	srcRect.w=32;
	srcRect.x=0;
	srcRect.y=0;
	
	destRect.x=xpo;
	destRect.y=ypo;
	destRect.w=srcRect.w;
	destRect.h=srcRect.h;
	if(r<640)
	{
		ced();
	}
}
void Chi::ced()
{
	if((cx-px<32&&px-cx<32&&cy==py)||(cy-py<32&&py-cy<32&&cx==px))
	{
		xpo=0+32*cch;
		ypo=640;
		cch=cch+1;
		if(cch==4)
		{
			finish();
		}
	}
}
void Chi::finish()
{
	if(gover==0)
	{
		cout<<"Victory!"<<endl;
	}
	gover=1;
	fin=1;
}
void Chi::Render()
{
	SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
}
