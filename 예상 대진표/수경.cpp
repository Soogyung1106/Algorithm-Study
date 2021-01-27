using namespace std;

int solution(int n, int a, int b)
{
    int tmp = 0;
    if(a>b){
        tmp = a; a = b;b = tmp;
    }
    
    int round = 1;
    while(1){
        //종료 조건
        if((a&1) && !(b&1) && (b-a == 1)) return round; 
        
        //홀수라면 짝수로 만들어주기
        if(a&1) a += 1; if(b&1) b += 1;
        
        //그 다음 라운드
        round++;
        a /= 2; b /= 2; 
    }
  
}
