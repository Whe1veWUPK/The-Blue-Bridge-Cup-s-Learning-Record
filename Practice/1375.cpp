#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N=60;
int n=52,p;
int dis[N][N];
int s[N];
bool st[N];
int get(char x){
	if(x<='Z'){
		return x-'A'+1;
    }
    return x-'a'+27;

}
char getC(int x){
	if(x<=26){
		return 'A'+x-1;
	}
	else{
		return 'a'+x-1;
	}
}
void dijkstra(){



    
    for(int i=1;i<=52;++i ){
        
    	s[i]=dis[i][26];
	}
	s[26]=0;
    st[26]=true;
    for(int i=1;i<=51;++i){
    	 int mv=0x3f3f3f3f,ind=-1;
         for(int j=1;j<=52;++j){
         	if(!st[j]&&s[j]<mv&&s[j]!=-1){
         		mv=s[j];
         		ind=j;
			 }
		 }
         if(ind==-1){
         	break;
		 }
		 //cout<<"cur index is "<<ind<<endl;
		 st[ind]=true;
		 for(int j=1;j<=52;++j){
		 	if((!st[j])&&dis[ind][j]!=-1){
		 	     if(s[j]==-1){

		 	     	 s[j]=s[ind]+dis[ind][j];
                     
				  }
				  else{
				     s[j]=min(s[j],s[ind]+dis[ind][j]);
				  }
				  //cout<<"update "<<j<<" "<<s[j]<<endl;
			 }
		 }
	
		
	}
}
int main(){
	memset(dis,-1,sizeof dis);
	scanf("%d",&p);
	while(p--){
		char x,y;
		int d;
        cin>>x>>y>>d;
        
        int a=get(x);
        int b=get(y);
        //cout<<a<<" "<<b<<" "<<d<<endl;
        //cout<<dis[a][b]<<endl;
        if(dis[a][b]==-1){
		     //cout<<"enter"<<endl;
		     dis[a][b]=d;
		     dis[b][a]=d;
		  
		 }
		 else{
		 	dis[a][b]=min(dis[a][b],d);
		 	dis[b][a]=min(dis[b][a],d);
		 }
	}


	dijkstra();
	int res=0x3f3f3f3f;
	int ind=-1;
	for(int i=1;i<=25;++i){
		if(s[i]<res&&s[i]!=-1){
			res=s[i];
			ind=i;
		}
	}
    //for(int i=1;i<=52;++i){
    	//cout<<s[i]<<" ";
	//}    
	//cout<<endl;


    cout<<getC(ind)<<" "<<res<<endl;
	return 0;
}