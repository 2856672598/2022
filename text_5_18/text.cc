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

