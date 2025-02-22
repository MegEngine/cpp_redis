// The MIT License (MIT)
//
// Copyright (c) 11/27/18 nick. <nbatkins@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.#ifndef CPP_REDIS_CONVERT_HPP
#ifndef CPP_REDIS_CONVERT_HPP
#define CPP_REDIS_CONVERT_HPP

#include <sstream>
#include <cpp_redis/misc/optional.hpp>
#include <cpp_redis/misc/macro.hpp>

namespace cpp_redis {

	class try_convert {
	public:
			template <class T>
			static enableIf<std::is_convertible<T, std::string>::value, optional_t<int64_t> > to_int(T value) {
				cpp_redis_try {
					std::stringstream stream(value);
					int64_t x;
					stream >> x;
					return optional_t<int64_t>(x);
				} cpp_redis_catch (std::exception &exc,) {
					return {};
				}
			}
	};

}


#endif //CPP_REDIS_CONVERT_HPP
