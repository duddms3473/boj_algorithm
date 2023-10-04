#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,q;
vector<int> vec;

int binarysearch(int m){
	int ans=0,mid,low=0,high=n-1;

	while(low<=high){
		mid=(low+high)/2;
		if(vec[mid]==m) return mid;
		else if(vec[mid]<m) {
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}

	return ans;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int tmp,m,num;

	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(),vec.end());

	for(int i=0;i<q;i++){
		cin>>m;
		if(vec[0]==m or vec[n-1]==m) {
			cout<<0<<"\n";
			continue;
		}
		
		num=binarysearch(m);

		cout<< num*(n-num-1)<<"\n";
	}

	return 0;
}
