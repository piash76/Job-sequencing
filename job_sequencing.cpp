
/*
You will be given n jobs with their starting and ending time. Find
maximum number of jobs that can be done by a single person.

3
10 20
20 30
12 25
2 jobs can be done

*/

#include<bits/stdc++.h>

using namespace std;




int main()
{
    int n;cin>>n;

    vector<pair<int,int>> v;

    for(int i=0;i<n;i++)
    {
        int st,fn;cin>>st>>fn;
        v.push_back({fn,st});  ///finish time , start time
    }

    sort(v.begin(),v.end());  ///sorting according to finish time

    int recent_job_time=-1; ///as jobs has not been taken
    int cnt=0;

    for(auto it:v)
    {
        int new_job_start=it.second;
        int new_job_finish=it.first;

        if(recent_job_time<=new_job_start)
        {
            cnt++;
            recent_job_time=new_job_finish;
        }
    }

    cout<<cnt<<endl;

    return 0;

}




