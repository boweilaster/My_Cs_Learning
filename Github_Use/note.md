### Github 本地上传云端过程

## 一.环境准备

* ``` git clone <仓库地址> ```
* 建立本地与远程仓库的 Tracking（追踪） 关系，并下载完整的版本数据库.

## 二.配置过滤器

* 创建 .gitignore 文件并写入 *.out, *.o, .vscode/。
* Git 在扫描文件变动时会跳过符合规则的文件，不将其计入 Index（索引）。

## 三.本地同步云端

* ``` git add .```
* 将工作区的改动提交到暂存区.

* ```git commit -m```
* 将暂存区打包成一个 提交对象 (Commit Object)，存入本地数据库。

* ```git push origin main ```
* 通过网络协议将本地数据库的变动同步到 GitHub 服务器。

