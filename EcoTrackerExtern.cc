#include "EcoTrackerExtern.hpp"

eco::ECO* create()
{
    eco::ECO *tracker = new eco::ECO();
    return tracker;
}

void init(eco::ECO *tracker, cv::Mat *im, const cv::Rect2f *rect, const char* cn_table_filename)
{
    eco::EcoParameters parameters;

    parameters.useCnFeature = false;
    parameters.cn_features.fparams.tablename = cn_table_filename;
    (*tracker).init(*im, *rect, parameters);
}

bool update(eco::ECO *tracker, const cv::Mat *frame, cv::Rect2f *roi)
{
    return (*tracker).update(*frame, *roi);
}

void dispose(eco::ECO *tracker)
{
    delete tracker;
}