/*
	��ȣ�Ҹ��� ���� ��ǰ�� ��õ �˰���

	1. ��� ����� ���� ���� ������ ������
	2. 1�� �� ���� �� ������
	3. 2�� �� ��ǰ ID�� ���� ���� ���� ��ǰ
	4. 
	���� �� �������� ���� ���, �� �������� ���� ������ ������ �� 2,3���� �ݺ� ����
	�̷��� �ؼ� �� ������ ���� ��ǰ�� ã�´�.

	���� ��ǰ ���� : ��ǰ ID, ����, ���� ����
*/

// ����ڴ� 1~N, ���� ��ǰ���� M�� 1~M
// �ʱ⿡�� ������ ģ���� �� ����� ����, ��ϵ� ���� ��ǰ�� ����.
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

// �켱 �ؽ����̺�� record ���̺� ����.
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

// ���� ��ǰ�� ����Ѵ�. pid�� ������. pID�� ��ǰ�� ã����, �� ��ǰ�� uid�� ���.
// pID�� 10������ �Ǵµ� �̰� �迭�� �� �� �ֳ�...? pID�� ��� ã����.
// �迭�� ���� �� ���� ����? ==> ������ �ؽ���.
// �ؽ����̺�� ���� pID�� ��������, �� ��忡 ������ �����ϴ°�.
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