#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
__gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> q[MAX];
//q[i].join(q[j]) ->  q[j]合并到q[i],q[j]清空 
