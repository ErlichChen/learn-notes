# DevOps

## Code Github

Enabling required reviews for pull requests

Repository administrators can enforce required reviews so that pull requests must have a specific number of approving reviews before they are merged.

Protected branches are available in All repositories.

Before enabling required reviews on a branch, you must first set the branch up as a protected branch.

1. On GitHub, navigate to main page of the repository.
2. Under your repository name, click Settings.
3. In the left menu, click Branches.
4. Next to "Branch protection rules", click Add rule.
5. Under "Branch name pattern", type the branch name or pattern you want to protect.
6. Select "Require pull request reviews before merging".
7. In the Required approving reviews drop-down menu, select the number of approving reviews you'd like to require on the branch.
8. Optionally, select "Dismiss stale pull request approvals when new commits are pushed." This dismisses a pull request approval review when a code-modifying commit is pushed to the branch.
9. Optionally, select Require review from Code Owners to require review from a code owner when the pull request affects code that has a designated owner.
10. Optionally, if the repository is part of an organization, select Restrict who can dismiss pull request reviews to search for and select the people or teams who can dismiss pull request reviews.
11. Optionally, select Include administrators. This enforces all configured restrictions for repository administrators.
12. Click Create.
