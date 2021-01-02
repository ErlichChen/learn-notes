# DevOps

## Code Github

启用拉取请求的必需审查。

仓库管理员可以实施必需审查，以便拉取请求在合并前必须通过特定数量的批准审查。

受保护分支适用于GitHub仓库。

在分支上启用必需审查前，必须首先将分支设置为受保护分支。

1. 在GitHub上，导航到仓库的主页面。
2. 在仓库名称下，单击Settings(设置)。
3. 在左侧菜单中，单击Branches(分支)。
4. 在"Branch protection rules(分支保护规则)"旁边，单击Add rule(添加规则)。
5. 在"Branch name pattern(分支名称模式)"下，输入您要保护的分支名称或模式。
6. 选择"Require pull request reviews before mergin"(合并前必需拉取请求审查)。
7. 在"Required approving review"(必需批准审查)下拉菜单中，选择希望在分支机构上要求的审批审查次数。
8. 可选择"Dismiss stale pull request approvals when new commits are pushed"(在推送新提交时忽略旧拉取请求)。当代码修改提交被推送到分支时，此操作忽略拉取请求批准审查。
9. 可选择"Require review from Code Owners"(代码所有者的必需审查)，以在拉取请求影响具有指定所有者的代码时，要求代码所有者进行审查。
10. 如果仓库是组织的一部分，视情况选择"Restrict who can dismiss pull request reviews"(限制可忽略拉取请求审查的人员)，以搜索和选择可忽略拉取请求审查的人员或团队。此选项不适用于个人仓库。
11. 视情况可选择"Include administrators"(包括管理员)。这将强制执行所有配置的仓库管理员限制。
12. 单击"Create"(创建)。
