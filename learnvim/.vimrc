set nocompatible              " 去除VI一致性,必须要添加
syntax on
set ts=4
set softtabstop=4
set shiftwidth=4
set expandtab
set autoindent

set clipboard^=unnamed,unnamedplus
set number
set relativenumber
set backspace=indent,eol,start
set wrap
set cursorline
set showcmd

set hlsearch
exec "nohlsearch"
set incsearch
set ignorecase
set smartcase

set wildmenu
set wildmode=list:longest,full
set history=200

filetype on                  " 必须要添加
filetype indent on
filetype plugin on
filetype plugin indent on
set mouse=r
set encoding=utf-8
"set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1 
"set fileencoding=utf-8
let &t_ut=''
set list
set listchars=tab:▸\ ,trail:▫
set scrolloff=5
set tw=0
set indentexpr=
set foldmethod=indent
set foldlevel=99
let &t_SI = "\<Esc>]50;CursorShape=1\x7"
let &t_SR = "\<Esc>]50;CursorShape=2\x7"
let &t_EI = "\<Esc>]50;CursorShape=0\x7"
set laststatus=2
"set autochdir
au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif

let mapleader=" "
noremap <LEADER><CR> :nohlsearch<CR>
map <LEADER>l :set splitright<CR>:vsplit<CR>
map <LEADER>k :set nosplitbelow<CR>:split<CR>
map <LEADER>h :set nosplitright<CR>:vsplit<CR>
map <LEADER>j :set splitbelow<CR>:split<CR>
"map <up> :res +5<CR>
"map <down> :res -5<CR>
"map <left> :vertical resize-5<CR>
"map <right> :vertical resize+5<CR>

"map s <nop>
"map <LEADER>sr :source $MYVIMRC<CR>
"execute "set <M-l>=\el"
"nnoremap <M-l> :<C-w>l
"execute "set <M-h>=\eh"
"nnoremap <M-h> <C-w>h
"execute "set <M-j>=\ej"
"nnoremap <M-j> <C-w>j
"execute "set <M-k>=\ek"
"nnoremap <M-k> <C-w>k
noremap <silent><tab>t :tabnew<cr>
noremap <silent><tab>c :tabclose<cr>
noremap <silent><tab>n :tabn<cr>
noremap <silent><tab>p :tabp<cr>

set shell=sh
" 设置包括vundle和初始化相关的runtime path
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" 另一种选择, 指定一个vundle安装插件的路径
"call vundle#begin('~/some/path/here')

" 让vundle管理插件版本,必须
Plugin 'VundleVim/Vundle.vim'

" 以下范例用来支持不同格式的插件安装.
" 请将安装插件的命令放在vundle#begin和vundle#end之间.
" Github上的插件
" 格式为 Plugin '用户名/插件仓库名'
"Plugin 'tpope/vim-fugitive'
" 来自 http://vim-scripts.org/vim/scripts.html 的插件
" Plugin '插件名称' 实际上是 Plugin 'vim-scripts/插件仓库名' 只是此处的用户名可以省略
"Plugin 'L9'
" 由Git支持但不再github上的插件仓库 Plugin 'git clone 后面的地址'
"Plugin 'git://git.wincent.com/command-t.git'
" 本地的Git仓库(例如自己的插件) Plugin 'file:///+本地插件仓库绝对路径'
"Plugin 'file:///home/gmarik/path/to/plugin'
" 插件在仓库的子目录中.
" 正确指定路径用以设置runtimepath. 以下范例插件在sparkup/vim目录下
"Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" 安装L9，如果已经安装过这个插件，可利用以下格式避免命名冲突
"Plugin 'ascenator/L9', {'name': 'newL9'}


" File navigation
"Plugin 'git://github.com/scrooloose/nerdtree.git', { 'on': 'NERDTreeToggle' }
Plugin 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }
Plugin 'Xuyuanp/nerdtree-git-plugin'
" 你的所有插件需要在下面这行之前
Plugin 'Valloric/YouCompleteMe'
Plugin 'junegunn/fzf'
Plugin 'junegunn/fzf.vim'

"Plugin 'vim-airline/vim-airline'
"Plugin 'vim-airline/vim-airline-themes'
Plugin 'connorholyday/vim-snazzy'

" Taglist
Plugin 'majutsushi/tagbar', { 'on': 'TagbarOpenAutoClose' }

" Error checking
Plugin 'w0rp/ale'

" Other visual enhancement
Plugin 'nathanaelkane/vim-indent-guides'
Plugin 'itchyny/vim-cursorword'

" Other useful utilities
Plugin 'terryma/vim-multiple-cursors'
Plugin 'junegunn/goyo.vim' " distraction free writing mode
Plugin 'tpope/vim-surround' " type ysks' to wrap the word with '' or type cs'` to change 'word' to `word`
Plugin 'godlygeek/tabular' " type ;Tabularize /= to align the =
Plugin 'gcmt/wildfire.vim' " in Visual mode, type i' to select all text in '', or type i) i] i} ip
Plugin 'scrooloose/nerdcommenter' " in <space>cc to comment a line

call vundle#end()            " 必须

" 忽视插件改变缩进,可以使用以下替代:
"filetype plugin on
"
" 常用的命令
" :PluginList       - 列出所有已配置的插件
" :PluginInstall     - 安装插件,追加 `!` 用以更新或使用 :PluginUpdate
" :PluginSearch foo - 搜索 foo ; 追加 `!` 清除本地缓存
" :PluginClean      - 清除未使用插件,需要确认; 追加 `!` 自动批准移除未使用插件
"
" 查阅 :h vundle 获取更多细节和wiki以及FAQ
" 将你自己对非插件片段放在这行之后
map <F2> :NERDTreeToggle<CR>


let g:SnazzyTransparent = 1
color snazzy


" ===
" === You Complete ME
" ===
let g:ycm_global_ycm_extra_conf = '~/.ycm_extra_conf.py'
nnoremap gd :YcmCompleter GoToDefinitionElseDeclaration<CR>
nnoremap g/ :YcmCompleter GetDoc<CR>
nnoremap gt :YcmCompleter GetType<CR>
nnoremap gr :YcmCompleter GoToReferences<CR>
let g:ycm_autoclose_preview_window_after_completion=0
let g:ycm_autoclose_preview_window_after_insertion=1
let g:ycm_use_clangd = 0
let g:ycm_python_interpreter_path = "/usr/local/bin/python3.6"
let g:ycm_python_binary_path = "/usr/local/bin/python3.6"
let g:ycm_key_list_select_completion = ['<C-j>','<Down>']
let g:ycm_key_list_previous_completion = ['<C-k>','<Up>']

" ==
" == NERDTree-git
" ==
let g:NERDTreeGitStatusIndicatorMapCustom = {
    \ "Modified"  : "✹",
    \ "Staged"    : "✚",
    \ "Untracked" : "✭",
    \ "Renamed"   : "➜",
    \ "Unmerged"  : "═",
    \ "Deleted"   : "✖",
    \ "Dirty"     : "✗",
    \ "Clean"     : "✔︎",
    \ "Unknown"   : "?"
    \ }
let g:NERDTreeGitStatusPorcelainVersion = 1



" ==
" == FuzzyFinder
" ==
map <LEADER>f :FZF<CR>



" ===
" === Taglist
" ===
map <LEADER>t :TagbarOpenAutoClose<CR>



" ===
" === ale
" ===
"let b:ale_linters = ['lualint']
"let b:ale_fixers = ['autopep8', 'yapf']


" ===
" === vim-indent-guide
" ===
let g:indent_guides_guide_size = 1
let g:indent_guides_start_level = 2
let g:indent_guides_enable_on_vim_startup = 1
let g:indent_guides_color_change_percent = 1
silent! unmap <LEADER>ig
autocmd WinEnter * silent! unmap <LEADER>ig

" ===
" === Goyo
" ===
map <LEADER>gy :Goyo<CR>

" airline
"let g:airline_powerline_fonts = 1  " 支持 powerline 字体
"let g:airline#extensions#tabline#enabled = 1 " 显示窗口tab和buffer
