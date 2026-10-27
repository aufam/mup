# mup

A lightweight C++ library for building HTML markup using C++ types and templates.

## Features

- Simple, composable markup expressions
- Compile-time attribute definitions
- Support for HTML void elements

## Quick Example

```cpp
#include <mup/html.h>
#include <iostream>

using namespace mup::html;

auto Page(const std::string &t, std::convertible_to<std::string> auto... content) {
    return html<"lang='en'">{
        head<>{
            meta<"charset='UTF-8'">,
            title<>{t},
        },
        body<>{
            h1<>{t},
            p<>{"Generated with C++."},
            a<"href='https://example.com'">{"Learn more"},
            std::move(content)...,
        }
    };
}

struct Task {
    std::string name;
};

auto TaskList(const std::vector<Task> &tasks) {
    return ul<"id='task-list'">{
        mup::each(tasks, [](auto &task) { return li<>{task.name}; }),
        mup::when(tasks.empty(), []() { return li<>{"No tasks"}; }),
    };
}

int main() {
    std::vector<Task> tasks = {
        {"task1"},
        {"task2"},
        {"task3"},
    };

    std::string page = Page(
        "Hello, World!",
        p<>{"TODO list:"},
        TaskList(tasks)
    );

    std::cout << page << std::endl;
}
```
