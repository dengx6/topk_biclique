#include "gstream.h"


gstream::gstream(string _data_path){
	fin.open(_data_path.c_str(), ios::in);
	if(!fin){
		cerr << "can not open " << _data_path << endl;
		system("pause");
	}
}

gstream::~gstream(){
	fin.close();
#ifdef GLOBAL_COMMENT
	cout << "OUT gstream destruction..." << endl;
#endif
}


bool gstream::hasnext(){
	return !fin.eof();
}

Edge* gstream::next(){
	char _buf[5000];
	if(fin.eof()){
		cout<<"error"<<endl;
		return NULL;
	}
	fin.getline(_buf, 4999, '\n');
	Edge* _newedge = new Edge(_buf);
	return _newedge;
}


