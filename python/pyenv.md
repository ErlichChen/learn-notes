# Python version management

## Installation

Automatic installation

```bash
curl -L https://raw.githubusercontent.com/yyuu/pyenv-installer/master/bin/pyenv-installer | bash
```

Manual installation

```bash
cd ~
git clone git://github.com/yyuu/pyenv.git .pyenv
echo 'export PYENV_ROOT="$HOME/.pyenv"' >> ~/.bashrc
echo 'export PATH="$PYENV_ROOT/bin:$PATH"' >> ~/.bashrc
echo 'eval "$(pyenv init -)"' >> ~/.bashrc
source ~/.bashrc
```

## Pyenv commands

```bash
# check local installed version
pyenv versions

# check remote installed version
pyenv install --list

# install & uninstall python version
pyenv install 3.6.0
pyenv uninstall 3.6.0

# swith python version
pyenv global 3.6.0
pyenv local 3.6.0
# priority shell > local > global

# refresh version information
pyenv rehash
```

## pyenv-virtualenv

```bash
# install pyenv for macos
brew install pyenv-virtualenv

# create virtual env
pyenv virtualenv 3.6.0 env-3.6.0

# list virtual env
pyenv virtualenvs

# activate & deactivate python env
pyenv activate env-name
pyenv deactivate

# uninstall python env
pyenv uninstall my-virtual-env
```