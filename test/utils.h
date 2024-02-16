#define SUITE(body) int main(int argc, char *argv[]) body
#define DESCRIBE(name, body)                                                   \
  {                                                                            \
    char *group = name;                                                        \
    body                                                                       \
  }
#define IT(name, body)                                                         \
  {                                                                            \
    printf("TEST[%s]: %s\n", group, name);                                     \
    body;                                                                      \
  }
#define ASSERT(assertion) assert(assertion);
