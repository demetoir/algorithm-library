//
//                    ACM ICPC 2003-2004
//               Northeastern European Region
//               Northern Subregional Contest
//
//     Problem C. Crankshaft
//     Authors: Nikolay Durov, Dmitry Shtukenberg
//     Solution: Dmitry Shtukenberg
//

#include <stdio.h>
#include <process.h>
#include <math.h>

int N;
int V;
int X[2000];
int Y[2000];

double XR = 0;
double YR = 0;
double Mass = 0;

void readXY( FILE* f ) {
  fscanf( f, "%d", &V );
  for( int i = 0; i < V; i++ )
    fscanf( f, "%d %d", X+i, Y+i );
  X[V] = X[0];
  X[V+1] = X[1];
  Y[V] = Y[0];
  Y[V+1] = Y[1];
}

int crosses( int* _X, int* _Y, int from, int to, double _x, double _y ) {
  if( (_X[from] < _x) != (_X[to] > _x) ) return 0;
  double t = (_X[to]-_x)/(-_X[from]+_X[to]);
  double yc = _Y[from]*t + _Y[to]*(1-t);
  return yc < _y;
}

int checkinside( int from, int to ) {
// 1. The edge should not cross other edges
  for( int i = 0; i < V; i++ ) {
    double d = (X[i+1]-X[i])*(Y[to]-Y[from]) - (X[to]-X[from])*(Y[i+1]-Y[i]);
    if( fabs(d) < 1e-10 ) return 0;
    double t1 = ((X[from]-X[i])*(Y[to]-Y[from])-(X[to]-X[from])*(Y[from]-Y[i]))/d;
    double t2 = -((X[i]-X[from])*(Y[i+1]-Y[i])-(X[i+1]-X[i])*(Y[i]-Y[from]))/d;

    if( t1 > 1e-10 && t1 < 1-1e-10 &&
	t2 > -1e-10 && t2 < 1+1e-10 ) return 0;
    if( t1 > -1e-10 && t1 < 1+1e-10 &&
	t2 > 1e-10 && t2 < 1-1e-10 ) return 0;
  }

// 2. The edge should lie inside polygon
  double goldcut = (-1+sqrt(5))/2;
  double xm = X[to]*goldcut + X[from]*(1-goldcut);
  double ym = Y[to]*goldcut + Y[from]*(1-goldcut);
  int cnt = 0;
  {
    for( int i = 0; i < V; i++ ) {
      if( X[from] != X[to] ) cnt += crosses( X, Y, i, i+1, xm, ym );
      else cnt += crosses( Y, X, i, i+1, ym, xm );
    }
  }
  return cnt % 2;
}

double dist( int from, int to ) {
  return sqrt((X[from]-X[to])*(X[from]-X[to]) + (Y[from]-Y[to])*(Y[from]-Y[to]));
}

int processtriangle() {
  for( int i = 0; i < V; i++ )
    if( V == 3 || checkinside( i, i+2 ) ) {
      double a = dist(i,i+1);
      double b = dist(i+1,i+2);
      double c = dist(i,i+2);
      double p = (a+b+c)/2;
      double trmass = sqrt(p*(p-a)*(p-b)*(p-c));
      Mass += trmass;
      XR += (X[i]+X[i+1]+X[i+2])*trmass/3;
      YR += (Y[i]+Y[i+1]+Y[i+2])*trmass/3;

      if( V == 3 ) return 0;

      for( int j = i+1; j < V+2; j++ ) {
        X[j] = X[j+1];
        Y[j] = Y[j+1];
      }
      V--;
      return 1;
    }
  printf( "Error!\n" );
  exit(1);
  return 0;
}

void computecm() {
  while( processtriangle() );
}

int main() {
  FILE* f = fopen( "cranksft.in", "rt" );
  fscanf( f, "%d", &N );
  for( int i = 0; i < N; i++ ) {
    readXY( f );
    computecm();
  }
  fclose( f );

  f = fopen( "cranksft.out", "wt" );
  if( !Mass ) exit(1);
  fprintf( f, "%lf %lf\n", XR/Mass, YR/Mass );
  fclose( f );

  return 0;
}
