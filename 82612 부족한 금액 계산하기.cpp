using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = ((long long)price * ((count*(count-1))/2 + count))- money;
    
    if (answer < 0) answer = 0;
    
    return answer;
}