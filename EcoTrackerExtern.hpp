#include "eco.hpp"

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
    __declspec(dllexport)
#endif
        eco::ECO* create();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
    __declspec(dllexport)
#endif
        void init(eco::ECO* tracker, cv::Mat* im, const cv::Rect2f* rect, const char* cn_table_filename);
#ifdef __cplusplus
}
#endif 

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
    __declspec(dllexport)
#endif
        bool update(eco::ECO* tracker, const cv::Mat* frame, cv::Rect2f* roi);
#ifdef __cplusplus
}
#endif 

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
    __declspec(dllexport)
#endif
        void dispose(eco::ECO* tracker);
#ifdef __cplusplus
}
#endif 
