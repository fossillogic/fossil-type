## **Fossil Type by Fossil Logic**

**Fossil Type** is a lightweight, cross-platform type system library written in C, with optional C++ wrappers. It provides stable type safety, introspection, deterministic limits, and functional adaptation across the Fossil ecosystem. Suitable for data processing, algorithms, AI systems, and embedded environments.

---

## Key Features

- **Cross-Platform & ABI-Stable**  
  Consistent type layer across Windows, macOS, Linux, and embedded targets with a C-friendly ABI and optional C++ wrappers.

- **Unified Core & Logical Types**  
  Fixed-width integers, unsigned/hex/oct variants, floating types, string/pointer abstractions, and **tri-state logic (`tribool`)** with deterministic limits.

- **Feature & Structural Extensions**  
  Supports `feature`, and `tribool` structural types for modular composition.

- **Runtime-Safe Casting & Conversion**  
  Explicit converters prevent unsafe narrowing or implicit promotions.

- **Type Introspection & Functional Interfaces**  
  Access type metadata, size, kind, and min/max values at runtime. Supports deterministic functional transformations.

- **Tribool Support**  
  Three-state logic: `false = 0`, `true = 1`, `unknown = 2`.

- **Zero External Dependencies**  
  Fully portable C implementation with optional C++ wrappers. No runtime dependencies.

---

## Fossil Type Limits

| Type       | Kind       | Min Value                      | Max Value                          | Size (bytes) |
|------------|-----------|--------------------------------|-----------------------------------|--------------|
| `i8`       | Signed    | -128                           | 127                               | 1            |
| `i16`      | Signed    | -32,768                        | 32,767                            | 2            |
| `i32`      | Signed    | -2,147,483,647                 | 2,147,483,647                     | 4            |
| `i64`      | Signed    | -9,223,372,036,854,775,808    | 9,223,372,036,854,775,807        | 8            |
| `u8`       | Unsigned  | 0                              | 255                               | 1            |
| `u16`      | Unsigned  | 0                              | 65,535                            | 2            |
| `u32`      | Unsigned  | 0                              | 4,294,967,295                     | 4            |
| `u64`      | Unsigned  | 0                              | 18,446,744,073,709,551,615       | 8            |
| `f32`      | Float     | -3.4028235e+38                 | 3.4028235e+38                     | 4            |
| `f64`      | Float     | -1.7976931e+308                | 1.7976931e+308                    | 8            |
| `bool`     | Boolean   | 0                              | 1                                 | 1            |
| `tribool`  | Tribool   | 0                              | 2                                 | 1            |
| `char`     | Signed    | -128                           | 127                               | 1            |
| `cstr`     | Pointer   | —                              | —                                 | 8 (pointer) |

---

## ***Prerequisites***

To get started, ensure you have the following installed:

- **Meson Build System**: If you don’t have Meson `1.8.0` or newer installed, follow the installation instructions on the official [Meson website](https://mesonbuild.com/Getting-meson.html).

### Adding Dependency

#### Adding via Meson Git Wrap

To add a git-wrap, place a `.wrap` file in `subprojects` with the Git repo URL and revision, then use `dependency('fossil-type')` in `meson.build` so Meson can fetch and build it automatically.

#### Integrate the Dependency:

Add the `fossil-type.wrap` file in your `subprojects` directory and include the following content:

```ini
[wrap-git]
url = https://github.com/fossillogic/fossil-type.git
revision = v0.1.0

[provide]
dependency_names = fossil-type
```

**Note**: For the best experience, always use the latest releases. Visit the [releases](https://github.com/fossillogic/fossil-type/releases) page for the latest versions.

## Build Configuration Options

Customize your build with the following Meson options:
	•	Enable Tests
To run the built-in test suite, configure Meson with:

```sh
meson setup builddir -Dwith_test=enabled
```

### Tests Double as Samples

The project is designed so that **test cases serve two purposes**:

- ✅ **Unit Tests** – validate the framework’s correctness.  
- 📖 **Usage Samples** – demonstrate how to use these libraries through test cases.  

This approach keeps the codebase compact and avoids redundant “hello world” style examples.  
Instead, the same code that proves correctness also teaches usage.  

This mirrors the **Meson build system** itself, which tests its own functionality by using Meson to test Meson.  
In the same way, Fossil Logic validates itself by demonstrating real-world usage in its own tests via Fossil Test.  

```bash
meson test -C builddir -v
```

Running the test suite gives you both verification and practical examples you can learn from.

## Contributing and Support

For those interested in contributing, reporting issues, or seeking support, please open an issue on the project repository or visit the [Fossil Logic Docs](https://fossillogic.com/docs) for more information. Your feedback and contributions are always welcome.
