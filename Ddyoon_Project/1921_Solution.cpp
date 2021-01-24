/*
	선호할만한 여행 상품은 추천 알고리즘

	1. 모든 사람이 가장 많이 예약한 여행지
	2. 1번 중 가장 싼 여행지
	3. 2번 중 상품 ID가 가장 작은 여행 상품
	4. 
	가장 싼 여행지가 없는 경우, 그 다음으로 많이 예약한 여행지 중 2,3번을 반복 수행
	이렇게 해서 될 때까지 여행 상품을 찾는다.

	여행 상품 구성 : 상품 ID, 지역, 가격 정보
*/

// 사용자는 1~N, 여행 상품지역 M은 1~M
// 초기에는 누구도 친구가 된 사용자 없고, 등록된 여행 상품도 없음.
// N(5~1000), M(2~10)

#define MAXN 1001
#define MAXM 11
#define MAX_TABLE 100007

typedef struct travelProduct {
	int pid;
	int area;
	int	price;

	void init(int pid, int area, int price) {
		this->pid = pid;
		this->area = area;
		this->price = price;
	}
};

typedef struct node {
	node *prev, *next;
	travelProduct product;
};

int maxN, maxM;
bool isFriend[MAXN][MAXN];
travelProduct productQueue[MAXM][MAXN];
int productCnt[MAXM];

// 우선 해시테이블과 record 테이블 생성.
node hTable[MAX_TABLE];
node RECORD[MAXN];

// hash func creation
int hash(int num) {
	return num % MAXN;
}


void init(int N, int M)
{
	maxN = N;
	maxM = M;

	for (int i = 0; i < maxM; i++) productCnt[i] = 0;

	for(int i=0;i<maxN;i++)
		for (int j = 0; j < maxN; j++) {
			isFriend[i][j] = false;
		}

}

void befriend(int uid1, int uid2)
{
	isFriend[uid1][uid2] = isFriend[uid2][uid1] = true;
}

// 여행 상품을 등록한다. pid는 고유값. pID로 상품을 찾으면, 그 상품을 uid에 등록.
// pID가 10억정도 되는데 이걸 배열로 할 수 있나...? pID로 어떻게 찾을까.
// 배열로 만들 수 없는 문제? ==> 무조건 해쉬다.
// 해쉬테이블로 만들어서 pID를 나눠놓고, 한 노드에 정보를 몰빵하는것.
void add(int pid, int area, int price)
{
	productQueue[area][productCnt[area]].init(pid, area, price);
	productCnt[area]++;
}

// 
void reserve(int uid, int pid)
{

}

int recommend(int uid)
{
	return 0;
}