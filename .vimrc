set nocompatible " I don't really understand what this does, but everyone seems to recommend it

"pathogen
execute pathogen#infect()
syntax on
filetype plugin indent on


"remove trailing whitespace
map <F12> :%s/\s\+$//<CR>


" colors
 syntax enable
 set t_Co=16
 set background=dark
 "let g:solarized_termcolors=256
 colorscheme solarized


" Use spaces instead of tabs
set expandtab
set smarttab
set backspace=2
set tabstop=2
set shiftwidth=2
set cursorline
set cursorcolumn

" indenting
set autoindent
filetype plugin indent on
set copyindent
set nowrap

"other
set ignorecase
set smartcase
set hlsearch
set incsearch
set noswapfile
set nobackup
set nowb
set showmatch

"linenumber
:set relativenumber
:set nu rnu


" Makes pasting text not add tabs to each line
" set paste fucks up SuperTab plugin...
" use paste toggle instead
set pastetoggle=<F10>

" searching
set incsearch
set ignorecase
set smartcase
set hlsearch
nmap <leader>q :nohlsearch<CR>

nnoremap B ^
nnoremap E $
noremap <C-j> 5j
noremap <C-k> 5k
noremap <C-l> 5l
noremap <C-h> 5h
noremap <S-t> :w<CR>
noremap <tab> <C-w><C-w>
"nnoremap <S-k>    :resize -4<CR>
"nnoremap <S-j>  :resize +4<CR>
nnoremap <Up>    :resize -4<CR>
nnoremap <Down>  :resize +4<CR>
nnoremap <Left>  :vertical resize -2<CR>
nnoremap <Right> :vertical resize +2<CR>
"nnoremap <S-h>  :vertical resize -4<CR>
"nnoremap <S-l> :vertical resize +4<CR>
"nnoremap > :vertical resize +2<CR>
"nnoremap < :vertical resize -2<CR>

 "insert mode remappings for brace autocomplete
 inoremap { {}<Esc>i
 inoremap ( ()<Esc>i
 inoremap [ []<Esc>i

 inoremap jk <esc>


 inoremap <C-h> <Left>
 inoremap <C-j> <Down>
 inoremap <C-k> <Up>
 inoremap <C-l> <Right>

map <C-n> :NERDTreeToggle<CR>
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
