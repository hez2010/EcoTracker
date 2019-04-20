#include "EcoTrackerExtern.hpp"

eco::ECO* create()
{
    eco::ECO *tracker = new eco::ECO();
    return tracker;
}

void init(eco::ECO *tracker, cv::Mat *im, const cv::Rect2f *rect)
{
    eco::EcoParameters parameters;
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