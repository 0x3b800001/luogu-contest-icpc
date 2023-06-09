# 由于洛谷更新，该项目被洛谷原装功能替代，因此停止更新。

# luogu-contest-icpc

让出题人能够在洛谷 IOI 赛制中把运行时间显示为提交时间距离开始时间的时间的总和。

由于洛谷特性，会先按分数排序，再按运行时间。因此可以起到类似 ICPC 赛制的效果。

## 具体效果

在**有分**时，显示运行时间为提交时间距离比赛开始的时间。例如，当比赛在 00:00 开始时，在 21:18:33 提交则会显示 21.30h 的运行时间。精确到分钟。

否则运行时间显示为 0ms。

空间总是显示为 0B。具体效果可以看 [我的私题](https://www.luogu.com.cn/problem/U295935) （使用的文件在 main 的 example 目录下，input.txt 为输入给 gen.cpp 的内容）。

没有罚时的效果，按现在的洛谷赛制有点难以实现。

## 原理

基于 checker 和自定义计分脚本。

## 使用指南

复制 checker.cpp，将 GetMinute("00:00"); 一行的时间改为比赛开始时间（北京时间，格式必须为 `HH:MM`）。然后编写你的 spj，我提供了 IOI_ICPC::quitWA()，IOI_ICPC::quitAC() 和 IOI_ICPC::quitUKE() 三个函数，不需要提示信息（因为洛谷设定比赛时不显示）。如果不需要 SPJ（即默认的全文比较），也需要使用 checker.cpp，使用 example 目录下的即可。

然后运行 gen.cpp，输入数据文件名前缀，时限（ms），空限（kb），Subtask 数，以及每个 Subtask 的对应数据点区间和总分。程序会自动生成 config.yml，以及若干个 txt。

接下来将 config.yml, checker.cpp 以及数据打包到一个 zip 中。别忘了给题目打上 Special Judge 标签，然后上传数据到洛谷。把所有 Subtask 和总分计分方式都改成自定义，然后依次复制生成的 Sub1.txt，Sub2.txt，……，以及总分复制 total.txt 的内容。

建议如果要出公开赛就留两个题目的版本，一个普通版用来加入主题库，一个用这个。

## 致谢

[Wdoi](https://www.luogu.com.cn/contest/53276) 提供灵感与基础代码

[@crpQwQ](https://www.luogu.com.cn/user/237940) 发现 [bug](https://www.luogu.com.cn/record/109365617)

[@CppWriter](https://www.luogu.com.cn/user/821638) [提议](https://www.luogu.com.cn/discuss/602958)
