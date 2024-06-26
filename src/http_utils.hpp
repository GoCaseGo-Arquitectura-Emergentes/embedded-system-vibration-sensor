#ifndef HTTP_UTILS_HPP
#define HTTP_UTILS_HPP
void updateWarning(const char* authToken, bool possibleCrash, int resourceId);
void checkResponseCode(int httpResponseCode);

#endif
