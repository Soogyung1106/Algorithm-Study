#include <iostream>
#include <vector>
using namespace std;

struct Fish{
	int y,x,d,n;
	Fish(int y, int x, int d, int n):y(y),x(x),d(d),n(n){}
};

const int dy[]={-1,-1,0,1,1,1,0,-1};
const int dx[]={0,-1,-1,-1,0,1,1,1};

bool inRange(int y, int x){
	return y>=0 && x>=0 && y<4 && x<4;
}

int solve(int y, int x, vector<vector<int>> field, vector<Fish> fishes){
	int ret,d;
    Fish& eaten = fishes[field[y][x]]; // 먹은 물고기

	d=eaten.d; // 상어 방향 전환
  ret=eaten.n;

  // 먹은 물고기의 빈칸 전환
	eaten.d=-1;
	field[y][x]=-1;

    // 모든 물고기 이동
	for(Fish& f:fishes){
		if(f.d==-1) continue; // 빈칸일 경우

    bool fail=false;
		int ny,nx,fd=f.d;

		while(true){
			ny=f.y+dy[f.d];
			nx=f.x+dx[f.d];

			if(inRange(ny,nx)&&(ny!=y||nx!=x)) break;

			if(++f.d>7) f.d=0; // 반시계 방향 회전

			if(f.d==fd){ // 이동할 수 있는 곳이 없을 경우
				fail=true;
				break;
			}
		}

		if(fail) continue;

		if(field[ny][nx]!=-1){ // 다른 물고기와 위치 변경
			fishes[field[ny][nx]].y=f.y;
			fishes[field[ny][nx]].x=f.x;
		}

		field[f.y][f.x]=field[ny][nx];
		field[ny][nx]=f.n-1;
		f.y=ny;
		f.x=nx;
	}

    // 백트래킹
	int ny=y, nx=x;
	while(true){
		ny+=dy[d];
		nx+=dx[d];

		if(!inRange(ny,nx)) break;
		if(field[ny][nx]==-1) continue;
        
		ret=max(ret,eaten.n+solve(ny,nx,field,fishes));
	}

	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<Fish> fishes(16,Fish(0,0,0,0));
	vector<vector<int>> field(4,vector<int>(4));

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			int n,d; cin>>n>>d;
			fishes[n-1].y=i;
			fishes[n-1].x=j;
			fishes[n-1].d=d-1;
			fishes[n-1].n=n;
			field[i][j]=n-1;
		}
	}

	cout<<solve(0,0,field,fishes);

	return 0;
}
