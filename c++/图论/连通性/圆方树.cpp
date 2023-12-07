#include <cstdio>
#include <vector>
#include <algorithm>

const int MN = 100005;

int N, M, cnt;
std::vector<int> G[MN], T[MN * 2];

int dfn[MN], low[MN], dfc;
int stk[MN], tp;

void Tarjan(int u) {
    printf("  Enter : #%d\n", u);
    low[u] = dfn[u] = ++dfc; // low ��ʼ��Ϊ��ǰ�ڵ� dfn
    stk[++tp] = u; // ����ջ��
    for (auto v : G[u]) { // ���� u �����ڽڵ�
        if (!dfn[v]) { // ���δ���ʹ�
            Tarjan(v); // �ݹ�
            low[u] = std::min(low[u], low[v]); // δ���ʵĺ� low ȡ min
            if (low[v] == dfn[u]) { // ��־���ҵ�һ���� u Ϊ���ĵ�˫��ͨ����
                ++cnt; // ���ӷ������
                printf("  Found a New BCC #%d.\n", cnt - N);
                // ����˫�г��� u �ĵ���ջ������Բ����������
                for (int x = 0; x != v; --tp) {
                    x = stk[tp];
                    T[cnt].push_back(x);
                    T[x].push_back(cnt);
                    printf("    BCC #%d has vertex #%d\n", cnt - N, x);
                }
                // ע�� u ����ҲҪ���ߣ�������ջ��
                T[cnt].push_back(u);
                T[u].push_back(cnt);
                printf("    BCC #%d has vertex #%d\n", cnt - N, u);
            }
        }
        else low[u] = std::min(low[u], dfn[v]); // �ѷ��ʵĺ� dfn ȡ min
    }
    printf("  Exit : #%d : low = %d\n", u, low[u]);
    printf("  Stack:\n    ");
    for (int i = 1; i <= tp; ++i) printf("%d, ", stk[i]);
    puts("");
}

int main() {
    scanf("%d%d", &N, &M);
    cnt = N; // ��˫ / �����Ŵ� N ��ʼ
    for (int i = 1; i <= M; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v); // ��˫���
        G[v].push_back(u);
    }
    // �������ͨͼ
    for (int u = 1; u <= N; ++u)
        if (!dfn[u]) Tarjan(u), --tp;
        // ע�⵽�˳� Tarjan ʱջ�л���һ��Ԫ�ؼ�����������ջ
    return 0;
}
