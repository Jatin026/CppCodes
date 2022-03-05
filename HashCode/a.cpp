#include<bits/stdc++.h>
using namespace std;
class Skill{
    
    public:
        string name;
        map<string,int> combo;
        Skill (string name){
            this->name=name;
        }

}; 
vector<Skill> skills_hai;
class Contributor{

    public:
        string name;
        //map<string,int> skill;
        int no_skill;
        void input(){
            cin>>name>>no_skill;
            for (int i = 0; i < no_skill; i++)
            {
                string skill_name;
                int level;
                bool f=1;
                cin>>skill_name>>level;
                for (auto x : skills_hai)
                {
                    if(x.name==skill_name){
                        x.combo[name]=level;
                        f=0;
                        break;
                    }
                }
                if(f){
                    Skill s1(skill_name);
                    s1.combo[name]=level;
                    skills_hai.push_back(s1);
                }   
            }  
        }
};
 
class Project{
    
    public:
        string name;
        int duration,score,best_before,requirements;
        map<string,int> skill_req;
        void input(){
            cin>>name>>duration>>score>>best_before>>requirements;
            for (int i = 0; i < requirements; i++)
            {
                string skill_name;
                int level;
                cin>>skill_name>>level;
                skill_req[skill_name]=level;
            }  
        }
    
};
 
      
//C++-> Anna->0   2 0
 
/*1)function -> two arrays->1 draft , 1 sure
2)function -> to increase skill level of contributor,delete the project and re-traverse with updated skill 



*/
void print(){
    for (auto x : skills_hai)
    {
        cout<<x.name<<"  ";
        for (auto ele : x.combo)
        {
            cout<<ele.first<<" "<<ele.second<<"\n";
        }
    }
}
int main(){
    int contributors,projects;
    cin>>contributors>>projects;
    vector<Contributor> arr(contributors); 
    vector<Project> proj(projects);
    
    
    for (int i = 0; i < contributors; i++)
    {
        arr[i].input();
    }
    for (int i = 0; i < projects; i++)
    {
        proj[i].input();
    }
    bool f=0;
    for (int i = 0; i < projects; i++)
    {
        vector<string> busy;
        for (auto j : proj[i].skill_req )
        {
            for (auto ski : skills_hai )
            {
                if(ski.name==j.first){
                    for (auto val : ski.combo )
                    {

                        if(val.second>=j.second){
                            busy.push_back(val.first);
                            goto label;
                        }
                        
                    }
                    
                }

            }
            label:;
        }
        if(busy.size()==proj[i].requirements){
            for (auto nam :  proj[i].skill_req)
            {
                for (auto x : skills_hai)
                 {
                    if(x.name==nam.first){
                        for (auto y : x.combo)
                        {
                             
                        }
                        
                    }
                }
                 
            }
            
        }
    }
    return 0;
}