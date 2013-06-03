<?php

/**
 * Implements hook_views_default_views().
 */
function commerce_sr_views_default_views(){
  $views = array();

  $view = new view();
  $view->name = 'recommendation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_sr';
  $view->human_name = 'Recommendation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'recommendations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'name' => 'name',
    'title' => 'title',
    'recommendation_price' => 'recommendation_price',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'recommendation_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Recommendation: commerce_product product_id */
  $handler->display->display_options['relationships']['commerce_product']['id'] = 'commerce_product';
  $handler->display->display_options['relationships']['commerce_product']['table'] = 'commerce_sr';
  $handler->display->display_options['relationships']['commerce_product']['field'] = 'commerce_product';
  /* Relationship: Recommendation: Creator ID */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_sr';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Recommendation: Commerce recommendation ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'commerce_sr';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Recommendation ID';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'commerce_product';
  /* Field: Recommendation: Price */
  $handler->display->display_options['fields']['recommendation_price']['id'] = 'recommendation_price';
  $handler->display->display_options['fields']['recommendation_price']['table'] = 'field_data_recommendation_price';
  $handler->display->display_options['fields']['recommendation_price']['field'] = 'recommendation_price';
  $handler->display->display_options['fields']['recommendation_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['recommendation_price']['type'] = 'commerce_price_formatted_amount';
  $handler->display->display_options['fields']['recommendation_price']['settings'] = array(
    'calculation' => FALSE,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'rec';
  $translatables['recommendation'] = array(
    t('Master'),
    t('recommendations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Commerce Product'),
    t('User'),
    t('Recommendation ID'),
    t('.'),
    t(','),
    t('Name'),
    t('Title'),
    t('Price'),
    t('Page'),
  );

  $views[$view->name] = $view;

  return $views;
}
