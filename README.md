# watch-app
An app of display watch

## Build

### Requirements

- Qt5
- OpenCV4

```shell
$ cmake -B build -DWATCH_TYPE=cv # (or qt)
$ cmake --build build
$ ./build/src/cv_watch # or (./build/src/qt_watch)
```

Exit with `Esc` key for cv watch, or press `Exit` for qt watch.