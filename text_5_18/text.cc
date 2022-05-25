// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// void Backtracking(vector<vector<char>> &arr, int x, int y, int &count)
// {
//     if (x < 0 || x >= arr.size() || y < 0 || y >= arr[0].size() || arr[x][y] == '#')
//         return;
//     count++;
//     //上下左右
//     arr[x][y] = '#';
//     Backtracking(arr, x - 1, y, count);
//     Backtracking(arr, x + 1, y, count);
//     Backtracking(arr, x, y - 1, count);
//     Backtracking(arr, x, y + 1, count);
// }

// int main()
// {
//     int m, n;
//     while (cin >> m >> n)
//     {
//         vector<vector<char>> arr(m,vector<char>(n));
//         int x, y;
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cin >> arr[i][j];
//                 if (arr[i][j] == '@')
//                 {
//                     x = i;
//                     y = j;
//                 }
//             }
//         }
//         int count = 0;
//         Backtracking(arr, x, y, count);
//         cout << count << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int n, m, k;
//     while (cin >> n >> m >> k)
//     {
//         vector<vector<double>> arr(n + 1, vector<double>(m + 1));
//         arr[1][1] = 1;
//         for (int i = 0; i < k; i++)
//         {
//             int x, y;
//             cin >> x >> y;
//             arr[x][y] = -1; //此处有蘑菇
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 if (i == 1 && j == 1)
//                 {
//                     arr[i][j] = 1;
//                     continue;
//                 }
//                 if (arr[i][j] == -1)
//                 {
//                     arr[i][j] = 0;
//                     continue;
//                 }
//                 if (i == n && j == m)
//                     arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
//                 else if (i == n)
//                     arr[i][j] = arr[i][j - 1] + arr[i - 1][j] * 0.5;
//                 else if (j == m)
//                     arr[i][j] = arr[i - 1][j] + arr[i][j - 1] * 0.5;
//                 else
//                     arr[i][j] = arr[i - 1][j] * 0.5 + arr[i][j - 1] * 0.5;
//             }
//         }
//         printf("%.2lf\n", arr[n][m]);
//     }
//     return 0;
// }

// #include <iostream>
// #include <pthread.h>
// #include <unistd.h>
// using namespace std;

// pthread_mutex_t mlock;
// pthread_cond_t t1,t2;

// int flag=0;
// void* Thread1(void* arg)
// {
//     while(true)
//     {
//         sleep(1);
//         pthread_mutex_lock(&mlock);
//         while(flag == 1){
//             pthread_cond_wait(&t1,&mlock);
//         }
//         cout<<"我是："<<(char*)arg<<"线程"<<endl;
//         flag++;
//         pthread_cond_signal(&t2);
//         pthread_mutex_unlock(&mlock);
//     }
// }

// void* Thread2(void* arg)
// {
//     while(true)
//     {
//         pthread_mutex_lock(&mlock);
//         while(flag == 0){
//             pthread_cond_wait(&t2,&mlock);
//         }
//         cout<<"我是："<<(char*)arg<<"线程"<<endl;
//         flag--;
//         pthread_cond_signal(&t1);
//         pthread_mutex_unlock(&mlock);
//     }
// }

// int main()
// {
//     pthread_cond_init(&t1,nullptr);
//     pthread_cond_init(&t2,nullptr);
//     pthread_mutex_init(&mlock,nullptr);

//     pthread_t tid1,tid2;
//     pthread_create(&tid1,nullptr,Thread1,(void*)"一号");
//     pthread_create(&tid2,nullptr,Thread2,(void*)"二号");

//     pthread_join(tid1,nullptr);
//     pthread_join(tid2,nullptr);
//     pthread_cond_destroy(&t1);
//     pthread_cond_destroy(&t2);
//     pthread_mutex_destroy(&mlock);
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <semaphore.h>
// #include <unistd.h>
// using namespace std;
// class Foo
// {

// public:
//     sem_t s1, s2, s3;
//     Foo()
//     {
//         sem_init(&s1, 0, 1);
//         sem_init(&s2, 0, 0);
//         sem_init(&s3, 0, 0);
//     }

//     ~Foo()
//     {
//         sem_destroy(&s1);
//         sem_destroy(&s2);
//         sem_destroy(&s3);
//     }
//     static void *one(void *arg)
//     {
//         pthread_detach(pthread_self());
//         Foo *obj = (Foo *)arg;
//         sem_wait(&obj->s1);
//         cout << "one" << endl;
//         sem_post(&obj->s2);
//     }
//     static void *two(void *arg)
//     {
//         pthread_detach(pthread_self());
//         Foo *obj = (Foo *)arg;
//         sem_wait(&obj->s2);
//         cout << "two" << endl;
//         sem_post(&obj->s3);
//     }

//     static void *three(void *arg)
//     {
//         pthread_detach(pthread_self());
//         Foo *obj = (Foo *)arg;
//         sem_wait(&obj->s3);
//         cout << "three" << endl;
//         sem_post(&obj->s1);
//     }
// };

// int main()
// {
//     Foo f;
//     pthread_t tid;
//     while (1)
//     {
//         pthread_create(&tid, nullptr, Foo::two, &f);
//         sleep(1);
//         pthread_create(&tid, nullptr, Foo::one, &f);
//         sleep(1);
//         pthread_create(&tid, nullptr, Foo::three, &f);
//     }

//     while (1);
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int DP(const string &s1,int pos1 ,const string& s2,int pos2)
// {
//     if(pos1 == s1.size() || pos2 == s2.size())
//         return 0;
//     if(s1[pos1] == s2[pos2]){
//         return 1+DP(s1,pos1+1,s2,pos2+1);
//     }
//     else{
//         return max(DP(s1,pos1+1,s2,pos2),DP(s1,pos1,s2,pos2+1));
//     }
// }

// int main()
// {
//     string s1,s2;
//     while(cin>>s1>>s2)
//     {
//         //cout<<DP(s1,0,s2,0)<<endl;
//         vector<vector<int>>nums(s1.size()+1,vector<int>(s2.size()+1));
//         for(int i=1;i<=(int)s1.size();i++)
//         {
//             for(int j =1;j<=(int)s2.size();j++)
//             {
//                 if(s1[i-1] == s2[j-1])
//                     nums[i][j] =nums[i-1][j-1]+1;
//                 else {
//                     nums[i][j] =max(nums[i-1][j],nums[i][j-1]);
//                 }
//             }
//         }
//         cout<<nums[s1.size()][s2.size()]<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     long arr[21] = {0};
//     arr[2] = 1;
//     arr[3] = 2;
//     for (int i = 4; i <= 20; i++)
//     {
//         arr[i] = (i - 1) * (arr[i - 1] + arr[i - 2]);
//     }
//     while (cin >> n)
//     {
//         cout << arr[n] << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int n;
//     while (cin >> n)
//     {
//         vector<int> nums(n, 0);
//         vector<int> flag(n, 1);
//         for (int i = 0; i < n; i++)
//             cin >> nums[i];
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i - 1; j >= 0; j--)
//             {
//                 if (nums[j] < nums[i])
//                 {
//                     flag[i] = max(flag[j] + 1, flag[i]);
//                 }
//             }
//         }
//         cout << *max_element(flag.begin(), flag.end()) << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// int main()
// {
// 	vector<string>arr(20, string(20, '0'));
// 	string tmp;
// 	while (cin >> arr[0])
// 	{
// 		for (int i = 1; i < 20; i++)
// 			cin >> arr[i];
// 		int flag = 0;
// 		for (int i = 0; i < 20; i++)
// 		{
// 			for (int j = 0; j < 20; j++)
// 			{
// 				if (arr[i][j] != '.') {
// 					//当前位置的8个方向进行判断
// 					int count = 0;
// 					for (int z = j - 1; z >= 0; z--) {
// 						if (arr[i][z] != arr[i][j])
// 							break;
// 						count++;
// 					}
// 					for (int z = j + 1; z < 20; z++) {
// 						if (arr[i][z] != arr[i][j])
// 							break;
// 						count++;
// 					}
// 					if (count >= 4) {
// 						flag = 1;
// 						goto END;
// 					}

// 					count = 0;
// 					//上下
// 					for (int z = i - 1; z >= 0; z--) {
// 						if (arr[i][j] != arr[z][j])
// 							break;
// 						count++;
// 					}
// 					for (int z = i + 1; z < 20; z++) {
// 						if (arr[i][j] != arr[z][j])
// 							break;
// 						count++;
// 					}
// 					if (count >= 4) {
// 						flag = 1;
// 						goto END;
// 					}
// 					//正对角
// 					count = 0;
// 					for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--)
// 					{
// 						if (arr[i][j] != arr[x][y])
// 							break;
// 						count++;
// 					}

// 					for (int x = i + 1, y = j + 1; x < 20 && y < 20; x++, y++)
// 					{
// 						if (arr[i][j] != arr[x][y])
// 							break;
// 						count++;
// 					}

// 					if (count >= 4)
// 					{
// 						flag = 1;
// 						goto END;
// 					}

// 					//斜对角
// 					count = 0;
// 					for (int x = i - 1, y = j + 1; x >= 0 && y < 20; x--, y++)
// 					{
// 						if (arr[i][j] != arr[x][y])
// 							break;
// 						count++;
// 					}

// 					for (int x = i + 1, y = j - 1; x < 20 && y >= 0; x++, y--)
// 					{
// 						if (arr[i][j] != arr[x][y])
// 							break;
// 						count++;
// 					}
// 					if (count >= 4)
// 					{
// 						flag = 1;
// 						goto END;
// 					}
// 				}
// 			}
// 		}
// 	END:
// 		if (flag == 1)
// 			cout << "Yes" << endl;
// 		else
// 			cout << "No" << endl;
// 	}
// 	return 0;
// }

// #include <iostream>
// #include <string>
// #include <vector>
// #include <stack>
// #include <unordered_map>
// #include <functional>
// using namespace std;

// int main()
// {
//     int n = 0;
//     while (cin >> n)
//     {
//         vector<string> nums(n);
//         for (int i = 0; i < n; i++)
//             cin >> nums[i];
//         stack<int>s;
// 		int i = 0;
// 		unordered_map<string, function<void()>>flag{
// 			{"+",[&]() {int num = s.top(); s.pop(); s.top() += num; }},
// 			{"-",[&]() {int num = s.top(); s.pop(); s.top() -= num; }},
// 			{"*",[&]() {int num = s.top(); s.pop(); s.top() *= num; }},
// 			{"/",[&]() {int num = s.top(); s.pop(); s.top() /= num; }}

// 		};
// 		while (i < (int)nums.size())
// 		{
// 			if (flag.find(nums[i]) != flag.end()) {
// 				flag[nums[i]]();
// 			}
// 			else
// 				s.push(stoi(nums[i]));
// 			i++;
// 		}
// 		cout<< s.top()<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
// 	string str;
// 	while(getline(cin,str))
// 	{
// 		for(int i=0;i<(int)str.size();i++)
// 		{
// 			if(isdigit(str[i]))
// 			{
// 				cout<<str[i];
// 			}
// 		}
// 		cout<<endl;
// 	}
// 	return 0;
// }

// #include <iostream>
// #include <vector>
// #include <string>
// #include <limits.h>
// using namespace std;

// void dfs(const vector<string> path, int x, int y, vector<vector<int>> &nums)
// {
//     //四个操作，上下左右
//     int operate[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//     for (int i = 0; i < 4; i++)
//     {
//         int nx = x + operate[i][0];
//         int ny = y + operate[i][1];
//         if (x >= 0 && x < 10 && nx >= 0 && nx < 10 && y >= 0 && y < 10 && ny >= 0 && ny < 10 && path[nx][ny] == '.' && nums[nx][ny] > nums[x][y] + 1)
//         {
//             nums[nx][ny] = nums[x][y] + 1;
//             dfs(path, nx, ny, nums);
//         }
//     }
// }

// int main()
// {
//     vector<string> path(10);
//     string tmp;
//     while (cin >> tmp)
//     {
//         for (int i = 1; i < 10; i++)
//         {
//             cin >> path[i];
//         }
//         vector<vector<int>> nums(10, vector<int>(10, INT_MAX));
//         nums[0][1] = 0;
//         dfs(path, 0, 1, nums);
//         cout << nums[9][8] << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
using namespace std;

// class Solution
// {
// public:
//     void Input(string &str, unordered_map<string, int> &flag)
//     {
//         stringstream ss(str);
//         string tmp;
//         while (ss >> tmp)
//         {
//             flag[tmp]++;
//         }
//     }
//     vector<string> uncommonFromSentences(string s1, string s2)
//     {
//         unordered_map<string, int> flag;
//         vector<string> ret;
//         Input(s1,flag);
//         Input(s2,flag);
//         for (const auto &e : flag)
//         {
//             if (e.second == 1)
//                 ret.push_back(e.first);
//         }
//         return ret;
//     }
// };

// class Solution
// {
// public:
//     bool containsDuplicate(vector<int> &nums)
//     {
//         unordered_map<int, int> flag;
//         for (auto e : nums)
//         {
//             flag[e]++;
//         }
//         for (auto e : flag)
//         {
//             if (e.second >= 2)
//                 return true;
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
//     {
//         unordered_set<int>flag;
//         for(auto e:nums1)
//             flag.insert(e);
//         unordered_set<int>tmp;
//         for(auto e:nums2)
//         {
//             if(flag.find(e)!=flag.end()){
//                 tmp.insert(e);
//             }
//         }
//         return vector<int>(tmp.begin(),tmp.end());
//     }
// };

// class Solution
// {
// public:
//     vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
//     {
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
//         vector<int> ret;
//         int begin1 = 0, begin2 = 0;
//         while (begin1 < (int)nums1.size() && begin2 < (int)nums2.size())
//         {
//             if(nums1[begin1] <nums2[begin2]){
//                 begin1++;
//             }
//             else if(nums1[begin1]>nums2[begin2]){
//                 begin2++;
//             }
//             else{
//                 ret.push_back(nums1[begin1]);
//                 begin1++;
//                 begin2++;
//             }
//         }
//         return ret;
//     }
// };

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int begin = 0, end = nums.size() / 2 - 1;
        while (end < (int)nums.size())
        {
            if (nums[begin] == nums[end])
                return nums[begin];
            begin++;
            end++;
        }
        return -1;
    }
};