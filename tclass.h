#include <algorithm>

using namespace std;


template<class Data_T,typename... Args>
class tclass
{
public:
	void example(Data_T&, Args&...);
	void example(Data_T&);

private:
	void intern(Data_T&, Args&...);
	void intern(Data_T&);
	
};

template<class Data_T,typename... Args>
void tclass<Data_T,Args...>::example(Data_T& data, Args&... args){

	// intern(ref(data), ref(args...));

}

template<class Data_T,typename... Args>
void tclass<Data_T,Args...>::example(Data_T&){
	// intern(ref(data));
}

template<class Data_T,typename... Args>
void tclass<Data_T,Args...>::intern(Data_T&, Args&...){

}

template<class Data_T,typename... Args>
void tclass<Data_T,Args...>::intern(Data_T&){

}