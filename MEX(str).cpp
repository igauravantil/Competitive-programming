#include  <bits/stdc++.h>
using namespace std;

int main (){
    long int t;
    cin >> t;
    while(t--){

        //Input and small stuff!
        string s="",main;
        cin >> main;
        bool start = false;
        if(main=="0"){
            s = main;
        }
        else{
for(int i =0 ; i < main.size();i++){
            if(start){
                s = s + main[i];
            }
            if(main[i]=='1'&&start==false){
                start = true;
                s = s + main[i];
            }
            else if(start==false){continue;}
        }
        }
        

        
        string answer = "" ;
        unordered_map<int ,int> umap;
        bool possible=false;
        for(int i = 0 ; i < s.size();i++){
            if(s[i]=='1'){
                umap[1]++;
            }
            else{
                umap[0]++;
            }
        }
        if(main=="0"){
            possible = true;
            cout << 1 << endl;
        }
        else if(umap[1]==s.size()){
            possible = true;
            cout << 0 <<endl;
        }

        //Storing the indexes
        vector<vector<int>> indexes;
        bool initial  = false;
        vector<int> temp;
		
        for(int i = 0 ; i < s.size()-1; i ++){
            if(s[i]==s[i+1]&&initial ==false){
				temp.push_back(i);
				initial = true;
				if(i+1==s.size()-1){
					temp.push_back(i+1);
					
					indexes.push_back(temp);
					temp.clear();
					initial  = false;
				}
			}
            else if(s[i]==s[i+1]&&initial){
                if(i+1==s.size()-1){
                    temp.push_back(i);
                    indexes.push_back(temp);
                    temp.clear();
                    initial = false;
                }
                
            }

			else if(s[i]!=s[i+1]&&initial){
                if(i+2<=s.size()-1){
                    if(s[i+1]!=s[i+2]){
					temp.push_back(i);
					indexes.push_back(temp);
					temp.clear();
					initial = false;
				}
                else if(s[i+1]==s[i+2]&&i+2==s.size()-1){
                    temp.push_back(i+2);
                    indexes.push_back(temp);
                    temp.clear();
                    initial=false;
                    break;
                }
                }
                
				
				if(i+1==s.size()-1){
					temp.push_back(i);
					indexes.push_back(temp);
					temp.clear();
					initial = false;
				}
			}
            
          
        }
        


        //Finding answer String!!!! 
        int indexOfIndexes=0;
        
        for(int i = 0 ; i < s.size(); i++){
            if(indexes.size()!=0){
                

            
            
            if(i>=indexes[indexOfIndexes][0] && i<=indexes[indexOfIndexes][1] ){
                if(s[i]=='0'){
                    
                    
                    if(i+2<indexes[indexOfIndexes][1]&&s[i+1]=='0'&&s[i+2]=='1'){
                        
                        answer = answer + "00";
                        
                        
                    }
                    
                    
                    else if(s[i+1]=='1'){
                        
                        for(int j = i+1;j<=indexes[indexOfIndexes][1];j++){
                            if(s[j]=='0'){
                                i=j-1;
                                break;
                            }
                            else if(s[j]!='0'&&j==indexes[indexOfIndexes][1]){
                                if(j==s.size()-1){
                                    answer = answer + '0';
                                    i=j;
                                    break;
                                }
                                else{
                                    i = j;
                                    indexOfIndexes++;
                                }
                            }

                        }
                    }
                    else{
                        if(i+1==indexes[indexOfIndexes][1]){
                            answer = answer  + '0';
                            if(indexOfIndexes!=indexes.size()-1){
                                if(s[indexes[indexOfIndexes+1][0] - 1]=='0'){
                                    for(int k = 0 ; k < (indexes[indexOfIndexes+1][0] -i)/2;k++){
                                        answer = answer +'0';
                                    }
                                    i = indexes[indexOfIndexes+1][0] - 2;
                                    indexOfIndexes++;
                                }
                                else{
                                    for(int k = 0 ; k < (indexes[indexOfIndexes+1][0] -i-1)/2;k++){
                                        answer = answer +'1';
                                    }
                                    i = indexes[indexOfIndexes+1][0] - 2;
                                    indexOfIndexes++;

                                }
                            }
                            else{
                                if(s[s.size()-1] =='0'){
                                    for(int k = 0 ; k < (s.size()-i)/2;k++){
                                        answer = answer + '1';
                                    }

                                    break;
                                }
                                else{
                                    for(int k = 0 ; k < (s.size()-i+1)/2 ;k++){
                                        answer = answer + '0';
                                    }
                                    break;

                                }

                            }
                        }
                        else{
                            
                            for(int j = i; j <=indexes[indexOfIndexes][1];j++){
                                if(s[j]=='1'){
                                    
                                    answer = answer +'0';
                                    i=j-1;
                                    break;
                                }
                                else{
                                    if(s[j]!='1'&&j==indexes[indexOfIndexes][1]){
                                        if(j==s.size()-1){
                                            answer = answer +'1';
                                            i=j;
                                            break;
                                        }
                                        else{
                                            answer+='0';
                                            i = j;
                                            if(indexOfIndexes<indexes.size()-1){
                                                indexOfIndexes++;
                                            }
                                            break;
                                        }
                                    }
                                }
                            }

                        }
                       }
                    }
                    else if(s[i]=='1'){
                        for(int  j = i;j <= indexes[indexOfIndexes][1];j++){
                            if(s[j]=='0'){
                                
                                answer = answer + '1';
                                i = j-1;
                                break;
                            }
                            else if(s[j]!='0'&&j==indexes[indexOfIndexes][1]){
                                if(j==s.size()-1){
                                    answer  = answer + '0';
                                    i=j;
                                    break;
                                }
                                else{
                                    answer = answer +'1';
                                    
                                    i=j;
                                    if(indexOfIndexes!=indexes.size()-1){
                                        indexOfIndexes++;
                                    }
                                    break;
                                    
                                }
                            }
                        }
                    }
            }
            else{
                
                    if(i==0){
                        
                        if(indexes[indexOfIndexes][0]==1){
                            
                            answer += '1';
                                    
                                    for(int j = i+1; j <=s.size()-1;j++){
                                        if(s[j]=='1'){
                                            i = j-1;
                                            if(j > indexes[indexOfIndexes][1]&&indexOfIndexes!= indexes.size()-1){
                                                indexOfIndexes++;
                                            }
                                            break;
                                        }
                                        else if(s[j]!='1' && j == s.size()-1){
                                            
                                            answer = answer + '1';
                                            i = j;
                                            break;
                                        }
                                    }
                                }
                        
                        else if(s[indexes[indexOfIndexes][0]-1]=='0'){
                            answer = answer +'1';
                            for(int k = 0 ; k < indexes[indexOfIndexes][0]/2; k++){
                                answer = answer  +'0';
                            }
                            i = indexes[indexOfIndexes][0]-2;
                        }
                        else if(s[indexes[indexOfIndexes][0]-1]=='1'){
                            for(int k = 0 ; k < (indexes[indexOfIndexes][0]+1)/2; k++){
                                answer = answer  +'1';
                            }
                            
                            i = indexes[indexOfIndexes][0]-2;
                        }
                    }
                    else{
                        if(i>indexes[indexOfIndexes][1]){
                            if(s[i]=='0'){
                                if(s[s.size()-1] =='0'){
                                    for(int  k = 0 ; k < ((s.size()+1-i)/2) + 1;k++){
                                        answer = answer +'0';
                                    }
                                    i = s.size()-1;
                                }
                                else{
                                    for(int k = 0 ; k < ((s.size()-i)/2) +1; k ++){
                                        answer = answer +'0';
                                    }
                                    i = s.size()-1;

                                }
                            }
                            else{
                                if(s[s.size()-1] =='1'){
                                    answer = answer +'1';
                                    for(int k = 0 ; k < ((s.size()-1-i)/2)+1; k ++){
                                        answer = answer +'0';
                                        
                                    }
                                    break;
                                }
                                else{
                                    for(int k = 0 ; k < ((s.size()-i)/2) + 1; k ++){
                                        answer = answer + '1';
                                    }
                                    break;
                                }
                            }
                        }
                        else if(indexes[indexOfIndexes][0]-i ==1){
                            if(indexOfIndexes>0){
                                if(i-1==indexes[indexOfIndexes-1][1]  ){
                                answer = answer  + s[i];
                            }
                            }
                            
                            
                                if(s[i]=='0'){
                                    
                                    for(int j = i+1; j <=s.size()-1;j++){
                                        if(s[j]=='0'){
                                            
                                            i = j-1;
                                            if(j > indexes[indexOfIndexes][1] && indexOfIndexes< indexes.size()-1){
                                                indexOfIndexes++;
                                            }
                                            break;
                                        }
                                        else if(s[j]!='0' && j == s.size()-1){
                                            answer = answer + '0';
                                            i = j;
                                            break;
                                        }
                                    }
                                }
                                else{
                                    
                                    for(int j = i+1; j <=s.size()-1;j++){
                                        if(s[j]=='1'){
                                            
                                            i = j-1;
                                            if(j > indexes[indexOfIndexes][1]&&indexOfIndexes!= indexes.size()-1){
                                                indexOfIndexes++;
                                            }
                                            break;
                                        }
                                        else if(s[j]!='1' && j == s.size()-1){
                                            answer = answer + '1';
                                            i = j;
                                            break;
                                        }
                                    }
                                }
                            
                        }
                        else if(i - indexes[indexOfIndexes-1][1] ==1){
                            if(s[i]=='0'){
                                
                                if(s[indexes[indexOfIndexes][0]-1]=='0'){
                                    answer = answer + '0';
                                    for(int k = 0 ; k < (indexes[indexOfIndexes][0]-1-i)/2;k++){
                                        answer = answer +'0';
                                    }
                                    i = indexes[indexOfIndexes][0]-2;
                                }
                                else{
                                   
                                    for(int k = 0 ; k < (indexes[indexOfIndexes][0]-i)/2;k++){
                                        answer = answer +'0';
                                    }
                                    i = indexes[indexOfIndexes][0]-1;

                                }
                            }
                            else{
                                answer = answer + '1';
                                if(s[indexes[indexOfIndexes][0]-1]=='1'){
                                    for(int k = 0 ; k < (indexes[indexOfIndexes][0]-1-i)/2;k++){
                                        answer = answer +'0';
                                        
                                    }
                                    i =indexes[indexOfIndexes][0];
                                }
                                else{
                                    for(int k = 0 ; k < ((indexes[indexOfIndexes][0]-i)/2) ;k++){
                                        answer = answer +'0';
                                        
                                    }
                                     i = indexes[indexOfIndexes][0]-2;

                                }
                            }
                        }
                    }
                }
            }

            //For outside of indexes!!


            else{
                
                    if(s[s.size()-1]=='0'){
                        for(int k = 0 ; k <( (s.size())/2) + 1; k++){
                            answer = answer + '1';
                        }
                        break;
                    }
                    if(s[s.size()-1]=='1'){
                        answer = answer +'1';
                        for(int k = 0 ; k <( (s.size())/2) + 1 ; k++){
                            answer = answer +'0';
                        }
                        break;
                    }
                
                
            }
        }
        if(possible){
            answer = "";
        }
        cout << answer << endl;
    }
}