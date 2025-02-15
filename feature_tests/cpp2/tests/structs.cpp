#include <iostream>
#include "../include/MyStruct.hpp"
#include "../include/MyEnum.hpp"
#include "../include/Opaque.hpp"
#include "assert.hpp"

int main(int argc, char *argv[]) {
    std::unique_ptr<Opaque> o = Opaque::new_();
    MyStruct s = MyStruct::new_();

    o->assert_struct(s);

    simple_assert_eq("struct values", s.a, 17);
    simple_assert_eq("struct values", s.b, true);
    simple_assert_eq("struct values", s.c, 209);
    simple_assert_eq("struct values", s.d, 1234);
    simple_assert_eq("struct values", s.e, 5991);
    simple_assert_eq("struct values", (uint32_t)s.f, (uint32_t)U'餐');
    simple_assert_eq("struct values", (uint32_t)s.g.AsFFI(), (uint32_t)MyEnum(MyEnum::B).AsFFI());
}
