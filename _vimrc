set nocompatible
source $VIMRUNTIME/vimrc_example.vim
source $VIMRUNTIME/mswin.vim
behave mswin

set diffexpr=MyDiff()
function MyDiff()
  let opt = '-a --binary '
  if &diffopt =~ 'icase' | let opt = opt . '-i ' | endif
  if &diffopt =~ 'iwhite' | let opt = opt . '-b ' | endif
  let arg1 = v:fname_in
  if arg1 =~ ' ' | let arg1 = '"' . arg1 . '"' | endif
  let arg2 = v:fname_new
  if arg2 =~ ' ' | let arg2 = '"' . arg2 . '"' | endif
  let arg3 = v:fname_out
  if arg3 =~ ' ' | let arg3 = '"' . arg3 . '"' | endif
  let eq = ''
  if $VIMRUNTIME =~ ' '
    if &sh =~ '\<cmd'
      let cmd = '""' . $VIMRUNTIME . '\diff"'
      let eq = '"'
    else
      let cmd = substitute($VIMRUNTIME, ' ', '" ', '') . '\diff"'
    endif
  else
    let cmd = $VIMRUNTIME . '\diff'
  endif
  silent execute '!' . cmd . ' ' . opt . arg1 . ' ' . arg2 . ' > ' . arg3 . eq
endfunction

inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap { {}<ESC>i
inoremap " ""<ESC>i
inoremap ' ''<ESC>i

set nobackup
set noswapfile
set autoindent
set cindent
set smartindent
set lines=40 columns=120
set tabstop=4
set shiftwidth=4
set showmatch
set nu
set hlsearch
set incsearch
colorscheme torte
set go=
syntax on
autocmd InsertLeave * se nocul
autocmd InsertLeave * se cul
set ruler
set showcmd
set scrolloff=2
set background=dark
set nocompatible
set fileencoding=gb2312
set fileencodings=utf-8,gb2312,gb18030,gbk,utf-16,big5

let g:miniBufExplMapCTabSwitchBufs=1
let g:miniBufExplMapWindowsNavVim=1
let g:miniBufExplMapWindowNavArrows=1

let Tlist_Sort_Type = "Name"
let Tlist_Use_Left_Window = 1
let Tlist_Compart_Format = 1
let Tlist_Exit_OnlyWindow=1
let Tlist_Auto_Open = 1

set tags=tags
set autochdir
set autoread

nmap <leader>w :w!<cr>
nmap <leader>f :find<cr>

"Create new file, auto add a filehead"
autocmd BufNewFile *.sh,*.java,*.py,*.bat exec ":call SetTitle()"
func SetTitle()
	if &filetype == 'sh' || &filetype == 'python'
		call setline(1,           "\# ===============================================================================")
		call append(line("."),    "\#"                                                           )
		call append(line(".")+1,  "\#       Filename: ".expand("%")                              )
		call append(line(".")+2,  "\#"															 )
		call append(line(".")+3,  "\#    Description: "                                          )
		call append(line(".")+4,  "\#"														     )
		call append(line(".")+5,  "\#        Version: 1.0"									     )
		call append(line(".")+6,  "\#        Created: ".strftime("%c")							 )
		call append(line(".")+7,  "\#       Revision: none"										 )
		call append(line(".")+8,  "\#       Compiler: gcc"										 )
		call append(line(".")+9,  "\#"															 )
		call append(line(".")+10, "\#         Author: qingchen"									 )
		call append(line(".")+11, "\#      	   Email: taojiang0101@gmail.com"					 )
		call append(line(".")+12, "\#   Organization: "                                          )
		call append(line(".")+13, "\#"                                                           )
		call append(line(".")+14, "\# ===============================================================================")
		call append(line(".")+15, "")
	else	
		call setline(1,           "\/*")
		call append(line("."),    " * ===============================================================================")
		call append(line(".")+1,  " * "                                                           )
		call append(line(".")+2,  " *        Filename: ".expand("%")                              )
		call append(line(".")+3,  " * "															  )
		call append(line(".")+4,  " *     Description: "                                          )
		call append(line(".")+5,  " * "														      )
		call append(line(".")+6,  " *         Version: 1.0"									      )
		call append(line(".")+7,  " *         Created: ".strftime("%c")							  )
		call append(line(".")+8,  " *        Revision: none"									  )
		call append(line(".")+9,  " *        Compiler: gcc"										  )
		call append(line(".")+10, " * "															  ) 
		call append(line(".")+11, " *          Author: qingchen"								  )
		call append(line(".")+12, " *           Email: taojiang0101@gmail.com"					  )
		call append(line(".")+13, " *    Organization: "                                          )
		call append(line(".")+14, " * "                                                           )
		call append(line(".")+15, " * ===============================================================================")
		call append(line(".")+16, " */")
		call append(line(".")+17, "")
	endif

	if &filetype == 'python'
		call append(line(".")+16, "\#!/usr/bin/env python")
		call append(line(".")+17, "")
		call append(line(".")+18, "")
	elseif &filetype == 'sh'
		call append(line(".")+16, "\#!/bin/bash")		
		call append(line(".")+17, "")
		call append(line(".")+18, "")
	endif

	autocmd BufNewFile * normal G
endfunction

"Press F5 to compile"
map <F5> :call CompileRunGcc()<cr>
func CompileRunGcc()
	exec "w"
	if &filetype == 'c'
		exec "!g++ % -o %<"
		exec "! ./%<"
	elseif &filetype == 'cpp'
		exec "!g++ % -o %<"
		exec "! ./%<"
	elseif &filetype == 'java'
		exec "!javac %"
		exec "! ./%<"
	elseif &filetype == 'sh'
		:! ./%
	elseif &filetype == 'python'
		exec "!python %"
	endif
endfunc

"Press F8 to debug"
map <F8> :call Rungdb()<cr>
func Rungdb()
	exec "w"
	exec "!g++ % -o %<"
	exec "!gdb ./%<"
endfunc

set completeopt=longest,menu
filetype plugin on
filetype indent on
