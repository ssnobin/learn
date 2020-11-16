let g:python3_host_prog = "/usr/bin/python3.6"

set nocompatible              " 去除VI一致性,必须要添加
syntax on
set ts=4
set softtabstop=4
set shiftwidth=4
set expandtab
set autoindent

set clipboard^=unnamed,unnamedplus
"set clipboard+=unnamedplus
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

noremap <silent><tab>t :tabnew<cr>
noremap <silent><tab>c :tabclose<cr>
noremap <silent><tab>n :tabn<cr>
noremap <silent><tab>p :tabp<cr>

set shell=sh
"plugin
call plug#begin("~/.vim/plugged")

Plug 'bling/vim-airline'
Plug 'Shougo/defx.nvim', { 'do': ':UpdateRemotePlugins' }

Plug 'junegunn/fzf'
Plug 'junegunn/fzf.vim'

Plug 'majutsushi/tagbar', { 'on': 'TagbarOpenAutoClose' }

Plug 'Yggdroot/indentLine'

Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'dense-analysis/ale'
call plug#end()

" ==
" == FuzzyFinder
" ==
map <LEADER>f :FZF<CR>

" ===
" === Taglist
" ===
map <LEADER>t :TagbarOpenAutoClose<CR>

" defx
call defx#custom#option('_', {
      \ 'winwidth': 30,
      \ 'split': 'vertical',
      \ 'direction': 'topleft',
      \ 'show_ignored_files': 0,
      \ 'buffer_name': '',
      \ 'toggle': 1,
      \ 'resume': 1
      \ })
"nmap <silent> <LEADER>d :Defx <cr>
nmap <silent> <LEADER>d :Defx<CR>
" Avoid the white space highting issue
"autocmd FileType defx match ExtraWhitespace /^^/
" Keymap in defx
autocmd FileType defx call s:defx_my_settings()
function! s:defx_my_settings() abort
  "IndentLinesDisable
  setl nospell
  setl signcolumn=no
  setl nonumber
  setl norelativenumber
  nnoremap <silent><buffer><expr> <CR>
  \ defx#is_directory() ?
  \ defx#do_action('open_or_close_tree') :
  \ defx#do_action('drop',)
  nmap <silent><buffer><expr> <2-LeftMouse>
  \ defx#is_directory() ?
  \ defx#do_action('open_or_close_tree') :
  \ defx#do_action('drop',)
  nnoremap <silent><buffer><expr> s defx#do_action('drop', 'split')
  nnoremap <silent><buffer><expr> v defx#do_action('drop', 'vsplit')
  nnoremap <silent><buffer><expr> t defx#do_action('drop', 'tabe')
  nnoremap <silent><buffer><expr> o defx#do_action('open_tree')
  nnoremap <silent><buffer><expr> O defx#do_action('open_tree_recursive')
  nnoremap <silent><buffer><expr> x defx#do_action('close_tree')
  nnoremap <silent><buffer><expr> C defx#do_action('copy')
  nnoremap <silent><buffer><expr> P defx#do_action('paste')
  nnoremap <silent><buffer><expr> M defx#do_action('rename')
  nnoremap <silent><buffer><expr> D defx#do_action('remove_trash')
  nnoremap <silent><buffer><expr> A defx#do_action('new_multiple_files')
  nnoremap <silent><buffer><expr> U defx#do_action('cd', ['..'])
  nnoremap <silent><buffer><expr> ~ defx#do_action('cd')
  nnoremap <silent><buffer><expr> . defx#do_action('toggle_ignored_files')
  nnoremap <silent><buffer><expr> <Space> defx#do_action('toggle_select')
  nnoremap <silent><buffer><expr> R defx#do_action('redraw')
  nnoremap <silent><buffer><expr> q defx#do_action('quit')
endfunction
nnoremap <silent> <Leader>c
\ :<C-u>Defx -resume -buffer-name=tab`tabpagenr()` -search=`expand('%:p')`<CR>

"indentLine
let g:indent_guides_guide_size            = 1  " 指定对齐线的尺寸
let g:indent_guides_start_level           = 2  " 从第二层开始可视化显示缩进

" ====
" ==== coc-vim插件配置
" ====
" inoremap命令用于在“插入模式”中进行映射按键
" 使用TAB键来启动代码补全触发器，并在前面加上字符并进行导航。
" 注意：使用命令'：verbose imap <tab>'来确保选项卡未由
"，然后再将其放入配置中
inoremap <silent><expr> <TAB>
      \ pumvisible() ? "\<C-n>" :
      \ <SID>check_back_space() ? "\<TAB>" :
      \ coc#refresh()
inoremap <expr><S-TAB> pumvisible() ? "\<C-p>" : "\<C-h>"

function! s:check_back_space() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction

" 将<TAB>用于选择范围
nmap <silent> <TAB> <Plug>(coc-range-select)
xmap <silent> <TAB> <Plug>(coc-range-select)


" ===
" === ale
" === need luac and luacheck
"ale
"始终开启标志列
let g:ale_sign_column_always = 1
let g:ale_set_highlights = 1
"自定义error和warning图标
let g:ale_sign_error = '✗'
let g:ale_sign_warning = '⚡'
"在vim自带的状态栏中整合ale
let g:ale_statusline_format = ['✗ %d', '⚡ %d', '✔ OK']
"显示Linter名称,出错或警告等相关信息
let g:ale_echo_msg_error_str = 'E'
let g:ale_echo_msg_warning_str = 'W'
let g:ale_echo_msg_format = '[%linter%] %s [%severity%]'
