;; this should be the path where the sfml libraries are located.
(setf *DEFAULT-PATHNAME-DEFAULTS* #P"~/Development/SFML/local/build/lib/")
;; this should be the path where the graphics and the music file
;; referenced below are located.
(ext:chdir #P"~/Development/SFML/local/demo/")
(defun load-sfml ()
  "Load all available SFML libraries."
  (format t "Loading sfml-window~%")
  (load "/home/meister/Development/clasp/build/clasp/Contents/execs/boehm/release/external-libs/libsfml-window.so")
  (format t "Loading sfml-graphics~%")
  (load "/home/meister/Development/clasp/build/clasp/Contents/execs/boehm/release/external-libs/libsfml-graphics.so")
  (format t "Loading sfml-audio~%")
  (load "/home/meister/Development/clasp/build/clasp/Contents/execs/boehm/release/external-libs/libsfml-audio.so")
  (format t "Libraries loaded~%"))

(load-sfml)
(let
    ((window (sf:make-render-window-vs '(400 400 32) "This is a clasp SFML Window"))
     (event (sf:make-event))
     (texture (sf:make-texture))
     (music (sf:make-music))
     (sprite nil)
     (event-type nil))
  (format t "Loading texture~%")
  (sf:load-from-file texture "world-nut2000.png" nil)
  (setf sprite (sf:make-sprite texture))
  (sf:open-from-file music "ACDC.ogg")
  (sf:play music)
  (loop while (sf:is-open window) do
	(loop while (sf:poll-event window event) do
	      (setf event-type (sf:get-type event))
	      (cond
	       ((eq event-type 'CLOSED) 
		(sf:close window))))
	(sf:clear window '(0 0 0 255))
	(sf:draw window sprite)
	(sf:display window))
  ;;(sf:stop music)
  )
