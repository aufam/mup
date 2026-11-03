# mup

A lightweight C++ library for building HTML markup using C++ types and templates.

## Features

- Simple, composable markup expressions
- Compile-time attribute definitions
- Dynamic attributes with runtime values
- Conditional and range-based rendering with `mup::when` and `mup::each`

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
        mup::each(tasks, [](auto &task) {
            return li<>{task.name};
        }),
        mup::when(tasks.empty(), []() {
            return li<>{"No tasks"};
        }),
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

## Attributes

`mup` supports both compile-time and runtime attributes.

### Compile-time attributes

Attributes can be specified as string literals in element template arguments:

```cpp
div<"id='app' class='container'">{
    p<>{"Hello, World!"}
};
```

These attributes are fixed at compile time and are suitable for static markup.

The library also provides named constexpr attribute definitions:

```cpp
div<(id="app", class_="container")>{
    p<>{"Hello, World!"}
};
```

Named attributes provide a more convenient alternative to writing raw attribute strings and help avoid spelling mistakes.

### Dynamic attributes

Attributes can also be assigned runtime values using `operator=`:

```cpp
std::string Key(std::string k, bool disable) {
    return button<(class_="key")>{
        (id = "key-" + k, hx_post = "press/" + k, aria_label = k, disabled = disable),

        k,
    };
}
```

This is just equal to:
```cpp
std::string Key(std::string k, bool disable) {
    auto btn = button<(class_="key")>{};

    btn.attributes = {
        "id=\"key-"+k+"\"",
        "hx-post=\"press/"+k+"\"",
        "aria-label=\""+k+"\"",
    };

    if (disable)
        btn.push_back("disabled");

    btn.content = k;

    return btn;
}
```


## Limitations

- **No complete HTML validation:**
  `mup` generates markup but does not guarantee that every element, attribute, or combination conforms to the HTML specification.
- **Attribute semantics:**
  HTML boolean attributes have special serialization rules. Ordinary attributes and boolean attributes must be handled according to their respective semantics.
