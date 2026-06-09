# How to contribute and rules:
### Contribute:
To contribute is very easy you just need to download a few things and build it:

First install llvm-project and build it in itside of it by doing the following:

```commandline
git clone --depth 1 https://github.com/llvm/llvm-project.git
cd llvm-project
cmake -S llvm -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
ninja -C build
```

Also we do testing via googletest you don't need to install it cmake should handle it already.

if you find any issue with cmake please contact or make a bug and explain the issue maybe i can fix it or something else!

### Rules:
If you want to contribute please follow these rules.,
- don't commit code in the main
- if you want to work on a feature please make a branch in a feature folder
- if your testing please make a branch in a testing folder
- if your fixing bugs or improving stuff please do it in the improve folder
- once your done please contact me or do a merge request i will take a look at it!
- also don't forget to document things its very important for everyone so its easier to understand

extra rules might be added or changed later try to stay up to date 