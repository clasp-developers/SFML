;; this should be the path where the sfml libraries are located.
;(setf *DEFAULT-PATHNAME-DEFAULTS* #P"~/Development/SFML/local/build/lib/")
;; this should be the path where the graphics and the music file
;; referenced below are located.
;(ext:chdir #P"~/Development/SFML/local/demo/")
(defun load-sfml ()
  "Load all available SFML libraries."
  (format t "Loading sfml-window~%")
  (let ((libdir (format nil "~a/build/clasp/Contents/execs/~a/~a/external-libs"
			(ext:getenv "CLASP_HOME")
			(ext:getenv "CLASP_GC")
			(ext:getenv "CLASP_VARIANT"))))
  (load (format nil "~a/libsfml-window.so" libdir))
  (load (format nil "~a/libsfml-graphics.so" libdir))
  (load (format nil "~a/libsfml-audio.so" libdir))
  (format t "Libraries loaded~%"))

(load-sfml)
(let
    ((window (sf:make-render-window-vs '(400 400 24) "This is a clasp SFML Window"))
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
