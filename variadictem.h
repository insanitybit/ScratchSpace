
template<class T, typename... Args> 
class variadictem
{
public:
	variadictem(Args...);
	
};

template<class T, typename... Args> 
variadictem<T, Args...>::variadictem(Args... a){

}
