#pragma once

#if MYS_DEBUG==2
	#define MYS_ERROR(x) std::cout <<x<<std::endl;
	#define MYS_LOG(x) std::cout<<x<<std::endl;
#elif MYS_DEBUG==1
	#define MYS_ERROR(x) std::cout <<x<<std::endl;
	#define MYS_LOG(x)
#else
	#define MYS_ERROR(x)
	#define MYS_LOG(x)
#endif


#ifdef MYSTIC_MSCPP
	#ifdef MYSTIC_LIB
		#define MYSTIC_API __declspec(dllexport)
	#else
		#define MYSTIC_API __declspec(dllimport)
	#endif
#else
	#define MYSTIC_API
#endif

#define MYSTIC_APPLICATION_START(ClassName) \
int main() \
{ \
    ClassName::Init(); \
    ClassName::RunInterface(); \
    return 0; \
}