<?php

/**
 * @file
 * Provides metadata for the commerce recommend.
 */

/**
 * Implements hook_entity_property_info().
 */
function commerce_sr_entity_property_info() {
  $info = array();

  $properties = &$info['recommendation']['properties'];

  $properties['id'] = array(
    'label' => t('Commerce recommendation ID'),
    'description' => t('The internal numeric ID of the commerce recommendation entity.'),
    'type' => 'integer',
    'schema field' => 'id',
  );
  $properties['type'] = array(
    'label' => t('Type'),
    'description' => t('The type of the commerce recommendation entity.'),
    'type' => 'token',
    'setter callback' => 'entity_property_verbatim_set',
    'required' => TRUE,
    'schema field' => 'type',
  );
  $properties['date'] = array(
    'label' => t('Commerce recommendation date'),
    'description' => t('The date the commerce recommendation entity was created.'),
    'type' => 'date',
    'setter callback' => 'entity_property_verbatim_set',
    'schema field' => 'date',
  );
  $properties['uid'] = array(
    'label' => t('Creator ID'),
    'type' => 'user',
    'description' => t('The unique ID of the commerce recommendation entity creator.'),
    'setter callback' => 'entity_property_verbatim_set',
    'schema field' => 'uid',
  );
  $properties['commerce_product'] = array(
    'label' => t('commerce_product'),
    'type' => 'commerce_product',
    'description' => t('Product id related with the commerce recommendation entity.'),
    'setter callback' => 'entity_property_verbatim_set',
    'schema field' => 'product_id',
  );

  return $info;
}
