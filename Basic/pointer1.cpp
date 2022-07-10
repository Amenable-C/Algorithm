#include <bits/stdc++.h>
using namespace std;

int v[10];

int main(){
	unordered_map<string, int> umap;
	
	umap.insert({"test1", 1});
	
	umap.emplace("test5", 5);
	
	umap["test1"] = 4;
	
	for(auto element : umap){
		cout << element.first << " : " << element.second << endl;
	}
	
	auto search = umap.find("test4");
	if(search != umap.end()){
		cout << "found : " << search->first << " " << (*search).second << endl;
	}else{
		cout << "not found..." << endl;
	}
	
	umap["test1"]++;
	cout << umap["test1"] << endl;
	
	cout << umap.size() << endl;
	umap.erase("test1");
	cout << umap.size() << endl;
	
	
	
	return 0;
}
