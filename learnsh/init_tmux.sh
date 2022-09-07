#e() {
    #echo $1
#}
#e hello
#session_list=(0 m1p cave p1 tw jp eu kr se tutu m2 tad tech)
session_list=(0 p1 tutu tech rec_lua recast tad_tu m1p m2 tu_2021 stress)
dir_list=(~ \
    #~/data/m1p_dev/ \
    ~/project/p1/ \
    #~/data/tw/ \
    #~/data/jp/ \
    #~/data/eu/ \
    #~/data/kr/ \
    #~/data/asia/ \
    ~/data/tututu/ \
    #~/project/my_tadpole_app/ \
    ~/tech/ \
    ~/project/recastnavigation_lua/ \
    ~/project/recastnavigation/ \
    ~/data/tad_tu/ \
    ~/data/m1p_cn/ \
    ~/project/Sedna/ \
    ~/project/tu_2021/ \
    ~/project/stress_robot/ \
)

hasSession() {
    tmux has-session -t $1 2>/dev/null
}

for ((i=0; i<${#session_list[*]}; i++))
do
    echo ${session_list[i]}
    echo ${dir_list[i]}
    if hasSession ${session_list[i]}; then
        echo "Session already exists"
    else
        tmux a -t 0
        cd ${dir_list[i]}
        tmux new-session -d -s ${session_list[i]}
        tmux a -t ${session_list[i]}
        tmux new-window
        tmux new-window
        tmux detach
        #tmux new-session -d -s m1p 'vim'
        ##tmux split-window -h -p 40 start_web_server
        ##tmux split-window -v
        ##tmux attach-session -d -t name_of_my_session
    fi
done


#tmux att -t get ||
#tmux \
  #new -s get -n capp \; \
  #send-keys 'get.capp' C-m \; \
  #neww -n emacs \; \
  #send-keys 'get.emacs' C-m \; \
  #neww -n git \; \
  #send-keys 'get.git' C-m \; \
  #neww -n mini \; \
  #send-keys 'get.mini' C-m \; \
  #neww -n port \; \
  #send-keys 'get.port' C-m \; \
  #neww -n rakudo \; \
  #send-keys 'get.rakudo' C-m \; \
  #neww -n neil \; \
  #send-keys 'get.neil && get.neil2 && exit' C-m \; \
  #neww -n red \; \
  #send-keys 'get.red && exit' C-m \; \
  #neww -n cpan \; \
  #send-keys 'get.cpan && exit' C-m \; \
  #selectw -t emacs


#tmux a -t m2 || cd ~/project/Sedna/ && tmux new -s m2 -d
#tmux a -t m1p || cd ~/data/m1plus/ && tmux new -s m1p -d
