#include "main.h"
#include "nvec.h"
#define rndC ofRandom(0,1)


struct pt
{
	vec point;
	vec4 clr ;
	vec nearestMean;
	pt()
	{
		clr = vec4(rndC,rndC,rndC,1.0) ;
	};
	void resetColor()
	{
		clr = vec4(rndC,rndC,rndC,1.0) ;
	}
};

struct mean
{
	vec point;
	vec4 clr ;
	int taken ;
	mean()
	{
		clr = vec4(rndC,rndC,rndC,1.0) ;
	};
};

bool isColourEqual( vec4 &a, vec4 &b)
{
	return ( a.r == b.r && a.g == b.g && a.b == b.b ) ;
}

int nPts ;
#define nMeans 55
pt pts[25000];
mean means[nMeans] ;
bool run = false;
bool attract = false;
vec cen ;
importer ptsReader ;
int num = nMeans ;

void setup() 
{
	glEnable(GL_SMOOTH);
	glEnable(GL_BLEND);

	#define rnd ofRandom(-20,20)
	for( int i =0 ; i < nPts * 0.5 ; i++ )
	{
		pts[i].point = vec(rnd*0.85,rnd*0.85,0.0) ;
		pts[i].clr = vec4( ofMap(pts[i].point.x , -20, 20,0,1) , ofMap(pts[i].point.y , -20, 20,0,1),0,1) ;
	}

	for( int i = nPts *0.5 ; i < nPts ; i++ )
	{
		pts[i].point = vec(rnd*0.15,rnd*0.15,0.0) ;
		pts[i].clr = vec4( ofMap(pts[i].point.x , -20, 20,0,1) , ofMap(pts[i].point.y , -20, 20,0,1),0,1) ;
	}


	//*importer*/ ptsReader = * new importer("C:/r.txt", 100000,10);
	//ptsReader.readPts_p5();
		for( int i =0 ; i < 20; i++ ) //ptsReader.nCnt
		{
			//ptsReader.nodes[i].pos.z = 0 ;
			//pts[i].point = ptsReader.nodes[i].pos ;
			pts[i].point = vec(ofRandom(0, 10), ofRandom(0, 10), ofRandom(0, 10));
			//pts[i].point.z = 0 ;
		}
	//nPts = ptsReader.nCnt ;
		nPts = 20;

	vec min,max ;
	//ptsReader.boundingBox(min,max) ;
	/*vec*/ cen = (min+max)*0.5 ;
	for( int i =0 ; i < nMeans ; i++ )means[i].point = ptsReader.nodes[int(ofRandom(0,ptsReader.nCnt))].pos ;

	nvec a;
	

}



void update( int value )
{

	if(run) 
	{
		for( int i =0 ; i < nPts ; i++ )
		{
			int nearest = 0;
			double nearestD = 10e16 ;
			for( int j =0 ; j < num ; j++ )
			{
				vec a = pts[i].point - means[j].point ;
				double d = a * a ;
				if( d < nearestD )
				{
					nearest = j ;
					nearestD = d;
				}	
			}
			pts[i].clr = means[nearest].clr ;
			pts[i].nearestMean = means[nearest].point ;
		}

		//

		for( int i =0 ; i < num ; i++ )
		{
			vec newMean ;
			int cnt = 0 ;
			for( int j =0 ; j < nPts ; j++ )
			{

				if( isColourEqual(pts[j].clr , means[i].clr ) )
				{
					newMean += pts[j].point ;
					cnt++ ;
				}


			}

			newMean /= cnt ;
			means[i].point = newMean ;
		}
	}

	if( attract )
	{
		for( int i =0 ; i < nPts ; i++ )
			pts[i].point += (pts[i].nearestMean - pts[i].point ).normalise() * 0.1 ;
	}
}

typedef pair<double,int> dis_ID ;

bool compare_dis (const dis_ID& first, const dis_ID& second)
{
	
	
	return ( first.first < second.first );
}

void draw()	
{
	backGround(0.75) ;
	
	//glPointSize(15);
	//for( int i =0 ; i < num ; i++ )
	//{
	//	vec4 cl = vec4(1,0,0,0) ;//means[i].clr ;
	//	glColor3f(cl.r,cl.g,cl.b) ;
	//	drawPoint(means[i].point) ;
	//}

	glPointSize(5) ;
	for( int i =0 ; i < nPts ; i++ )
	{
		vec4 cl = pts[i].clr ;
		float l = cl.r * 0.57 + cl.g * 0.27 + cl.b * 0.11 ;
		//cl = vec4(l,l,l,l) ;
		glColor3f(cl.r,cl.g,cl.b) ; //
		drawPoint(pts[i].point) ;
	}


	//for( int i =0 ; i < num ; i++ )means[i].taken = 0 ;
	//list<dis_ID> dis_IDs ;

	//list<dis_ID>::iterator it;

	//glColor3f(0,0,0) ;
	//	for( int i =0 ; i < num ; i++ )
	//	{
	//		double d = 1 * 10e32 ;
	//		dis_IDs.clear() ;
	//		int nearest = 0 ;
	//			for( int j =0 ; j < num ; j++ )
	//			{
	//				if(i==j)continue ;
	//				//if( means[j].taken )continue ;
	//				double dis =  (means[i].point - means[j].point) * (means[i].point - means[j].point) ;
	//				dis_ID e;
	//				e.first = dis ;
	//				e.second = j ;

	//				dis_IDs.push_back(e) ;

	//				if( dis < d  )
	//				{
	//					d = dis ;
	//					nearest = j ;
	//				}
	//			}

	//		dis_IDs.sort(compare_dis);
	//		it = dis_IDs.begin() ;
	//		//it--;
	//		dis_ID nID = *it ;
	//		int id = nID.second ;
	//		drawLine(means[i].point,means[id].point) ;
	//		/*it++;
	//		nID = *it ;
	//		id = nID.second ;
	//		drawLine(means[i].point,means[id].point) ;*/
	//		//it++;
	//		/*neearestID = *it ;
	//		int id = neearestID.second ;
	//		drawLine(means[i].point,means[id].point) ;*/
	//		


	//		means[nearest].taken = true ; 
	//	}

}

void keyPress (unsigned char k, int xm, int ym)
{
	
	//if (k == 'i' || k == 'I')
	
	if( k == 'u') 
	{
		for( int i =0 ; i < nMeans ; i++ )means[i].point = pts[int(ofRandom(0,nPts))].point ;
		run = !run ;
		attract = !run ;
	}
	if( k == 'a') 
	{
		attract = !attract ;
		run = !attract ;
	}
	//for( int i =0 ; i < nPts ; i++ ) pts[i].resetColor() ;
	if( k == 'r' )setup() ;
		//for( int i =0 ; i < nMeans ; i++ )means[i].point = ptsReader.nodes[int(ofRandom(0,ptsReader.nCnt))].pos ;

	if( k == '=') num+=1 ;
	if( k == '-') num-=1 ;
	
}

void mousePress(int b,int s,int x,int y) 
{

}

void mouseMotion(int x,int y) 
{
	
}




