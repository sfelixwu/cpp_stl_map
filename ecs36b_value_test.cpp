
#include <map>
#include <json/json.h>
#include "ecs36b_Common.h"

typedef std::map<std::string, Json::Value> ObjectValues;

class ecs36b_value
{
private:
protected:
public:
  ObjectValues attr_map;
  Json::Value& operator[](const char *key);
};

Json::Value&
ecs36b_value::operator[]
(const char *key)
{
  ObjectValues::iterator it = (this->attr_map).lower_bound(key);
  if ((it != (this->attr_map).end()) &&
      ((*it).first == key))
    {
      return (*it).second;
    }
  
  ObjectValues::value_type defaultValue(key, Json::Value::null);
  it = (this->attr_map).insert(it, defaultValue);
  Json::Value& ret_value = (*it).second;

  return ret_value;
}

int
main(void)
{
  ecs36b_value myvalue;
  myvalue["key1"] = 123;
  std::cout << myvalue["key1"] << std::endl;
  return 0;
}
