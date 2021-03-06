<?php

foreach($pages->get($wire->config->adminRootPageID)->children("check_access=0") as $p) {

	if(!$p->viewable()) continue; 

	$showItem = $user->isSuperuser() ? true : false;
	$info = array();

	if(!$showItem) { 
		$checkPages = $p->numChildren ? $p->children("check_access=0") : array($p); 
		foreach($checkPages as $child) {
			if($child->viewable()) {
				$showItem = true;
				break;
			}
		}
	}

	if($showItem) { 
		$class = strpos($page->path, $p->path) === 0 ? " class='active'" : '';
		echo "\n\t\t\t<li$class><a href='{$p->url}'>" . strip_tags($p->get('title|name')) . "</a></li>"; 
	}
}
